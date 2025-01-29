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
  if(empty())   {
    Item* item = new Item();
      
    item->val[ARRSIZE-1] = val;
    item->first = ARRSIZE-1;
    item->last = ARRSIZE;
      
    head_ = item;
    tail_ = item;
  }
  else {
    
    if(!(tail_->no_space_last())) {
      tail_->val[tail_->last] = val;
    }
    else {
      Item* item = new Item();
      
      item->val[0] = val;
      
      Item* temp = tail_;
      tail_ = item;
      item->prev = temp;
      temp->next = item;
    }
  }
  tail_->last++;
  size_++;
}

std::string const & ULListStr::back() const{
  return tail_->val[(tail_->last)-1];
}

std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}

//helper function for getValAtLoc
//goes through correct amount of nodes to find when 
ULListStr::Item* item_jump(size_t jump_num, ULListStr::Item* node) { 
  if (jump_num > 0)   {
    jump_num--;
    return item_jump(jump_num, node->next);
  }
  else  {
    return node;
  }
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  size_t actual_point = (head_->first) + loc;
  size_t jump_num= actual_point / 10;
  int index_local = actual_point % 10;
  if(loc >= size_)   {
    return nullptr;
  }
  Item* jumped_item = item_jump(jump_num, head_);
  return &jumped_item->val[index_local];
}

void ULListStr::pop_back(){
  if(size_ == 0) {
    throw std::runtime_error("popback fail, size 0");
  }
  else if (size_ == 1) {
      delete tail_;
      tail_ = nullptr;
      head_ = nullptr;
      size_--;
      return ;
  }
  else if(tail_->last == 0) {
      Item* temp = tail_;
      tail_ = tail_->prev;
      tail_->next = nullptr;
      delete temp;
  }
  tail_->val[tail_->last - 1] = ""; //sets the popped string empty just in case
  tail_->last--; //goes back on last so will get overwritten with next add
  size_--;
}
