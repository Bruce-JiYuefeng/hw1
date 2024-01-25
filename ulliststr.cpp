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


void ULListStr::push_back(const std::string& val){
  if (tail_ == nullptr || tail_->last == ARRSIZE){
    Item* newItem = new Item();
    newItem->prev = tail_;
    if(tail_ != nullptr){
      tail_->next = newItem;
    }
    tail_ = newItem;
    if (head_ == nullptr){
      head_ = newItem;
    }
  }
  tail_->val[tail_->last] = val;
  tail_->last++;
  size_++;
}

void ULListStr::push_front(const std::string& val){
  if (head_ == NULL || head_->first == 0){
    Item* newItem = new Item();
    newItem->next = head_;
    if(head_ != nullptr){
      head_->prev = newItem;
    }
    head_ = newItem;
    head_->first = ARRSIZE;
    head_->last = ARRSIZE;
    if(tail_ == nullptr){
      tail_ = newItem;
    }
  }
  head_->first--;
  head_->val[head_->first] = val;
  size_++;
}

void ULListStr::pop_back(){
  if(empty()){
    throw std::out_of_range("list is empty"); 
  }
  tail_->last--;
  size_--;

  if(tail_->last == tail_->first){
    Item* temp = tail_;
    tail_ = tail_->prev;
    delete temp;
    if(tail_ != nullptr){
      tail_->next = nullptr;
    }
    else {
      head_ = nullptr;
    }
  }
}

void ULListStr::pop_front(){
  if(empty()){
    throw std::out_of_range("list is empty");
  }
  head_->first++;
  size_--;

  if(head_->first == head_->last){
    Item* temp = head_;
    head_ = head_->next;
    delete temp;
    if(head_ != nullptr){
      head_->prev = nullptr;
    }
    else {
      tail_ = nullptr;
    }
  }
}

std::string const& ULListStr::back() const{
  if(empty()){
    throw std::out_of_range("list is empty"); 
  }
  return tail_->val[tail_->last - 1];
}

std::string const& ULListStr::front() const{
  if(empty()){
    throw std::out_of_range("list is empty"); 
  }
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  if(loc >= size_) {
    return nullptr; 
  }

  Item* current = head_;

  while(current != nullptr){
    size_t numElementsInItem = current->last - current->first;
    if(loc < numElementsInItem) {
      return &current->val[current->first + loc];
    }

    loc -= numElementsInItem;
    current = current->next;
  }

  return nullptr;
}