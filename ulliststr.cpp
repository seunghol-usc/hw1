#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE


//helper function: return size of tail_
size_t ULListStr::tail_size() const {
  return (tail_->last) - (tail_->first);
}

//helper function: return size of head_
size_t ULListStr::head_size() const {
  return (head_->last) - (head_->first);
}



/**
  * Adds a new value to the back of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::push_back(const std::string& val) {
  size_++;

  //if there is nothing
  if (head_ == nullptr) {
    Item* it = new Item();
    (it->val)[0] = val;
    it->last = 1;
    
    head_ = it;
    tail_ = it;

    return;
  }

  //tail is full
  if (tail_size() == ARRSIZE) {
    Item* it = new Item();
    (it->val)[0] = val;
    it->last = 1;
    
    it->prev = tail_;
    tail_->next = it;
    tail_ = it;

    return;
  }

  (tail_->val)[(tail_->last)++] = val;
}

/**
  * Removes a value from the back of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::pop_back() {
  // list is empty
  if (head_ == nullptr) {
    return;
  }

  size_--;

  // list has one val
  if (tail_size() == 1) {
    Item* tmp = tail_->prev;
    if (tmp != nullptr) tmp->next = nullptr;
    if (head_ == tail_) head_ = nullptr;
    delete tail_;
    tail_ = tmp;
    return;
  }

  // otherwise
  (tail_->last)--;
}

/**
  * Adds a new value to the front of the list.
  * If there is room before the 'first' value in
  * the head node add it there, otherwise, 
  * allocate a new head node.
  *   - MUST RUN in O(1)
  */
void ULListStr::push_front(const std::string& val) {
  size_++;

  //if there is nothing
  if (head_ == nullptr) {
    Item* it = new Item();
    (it->val)[0] = val;
    it->last = 1;
    
    head_ = it;
    tail_ = it;

    return;
  }

  //head is full
  if (head_size() == ARRSIZE || head_->first == 0) {
    Item* it = new Item();
    (it->val)[ARRSIZE-1] = val;
    it->last = ARRSIZE;
    it->first = ARRSIZE-1;
    
    it->next = head_;
    head_->prev = it;
    head_ = it;

    return;
  }

  // otherwise
  (head_->val)[--(head_->first)] = val;
}

/**
  * Removes a value from the front of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::pop_front() {
  // list is empty
  if (head_ == nullptr) {
    return;
  }

  size_--;

  //head has one element
  if (head_size() == 1) {
    Item* tmp = head_->next;
    if (tmp != nullptr) tmp->prev = nullptr;
    if (tail_ == head_) tail_ = nullptr;
    delete head_;
    head_ = tmp;

    return;
  }

  (head_->first)++;
}

/**
  * Returns a const reference to the back element
  *   - MUST RUN in O(1)
  */
std::string const & ULListStr::back() const {
  // list is empty
  if (head_ == nullptr) {
    return NULL;
  }

  return (tail_->val)[(tail_->last)-1];
}

/**
  * Returns a const reference to the front element
  *   - MUST RUN in O(1)
  */
std::string const & ULListStr::front() const {
  // list is empty
  if (head_ == nullptr) {
    return NULL;
  }

  return (head_->val)[head_->first];
}

/** 
  * Returns a pointer to the item at index, loc,
  *  if loc is valid and NULL otherwise
  *   - MUST RUN in O(n) 
  */
std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc >= size_) return NULL;

  Item* it = head_;
  size_t index = it->first, curr_pos = 0;

  while (curr_pos < loc) {
    index++; curr_pos++;
    if (index >= it->last) {
      it = it->next;
      index = it->first;
    }
  }

  return (it->val + index);
}




// MY CODE ENDS HERE


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
