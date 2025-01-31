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
    
    if(!(tail_->last == 10)) {
      tail_->val[tail_->last] = val;
      tail_->last++;
    }
    else {
      Item* item = new Item();
      
      item->val[0] = val;
      
      Item* temp = tail_;
      tail_ = item;
      item->first = 0;
      item->last = 1;
      item->prev = temp;
      temp->next = item;
    }
  }
  size_++;
}


//creates new node with elemnt at the first spot if no other nodes are present;
//otherwise put it behind the first element, creating new node only fif necessary
void ULListStr::push_front(const std::string& val){
    if(empty())   {
    Item* item = new Item();
      
    item->val[0] = val;
    item->first = 0;
    item->last = 1;
      
    head_ = item;
    tail_ = item;
  }
  else {
    
    if(head_->first > 0) {
      head_->val[(head_->first) - 1] = val;
      head_->first--;
    }
    else {
      Item* item = new Item();
      item->val[9] = val;
      item->last = 10;
      item->first = 9;
      Item* temp = head_;
      head_ = item;
      item->next = temp;
      temp->prev = item;
    }
  }
  size_++;
}



std::string const & ULListStr::back() const{
  if(size_ == 0)   {
    throw std::runtime_error("back() fail, size 0");
  }
  return tail_->val[(tail_->last)-1];
}

std::string const & ULListStr::front() const{
  if(size_ == 0) {
    throw std::runtime_error("front() fail, size 0");
  }
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


void ULListStr::pop_front() {
     if (size_ == 0) {
      throw std::runtime_error("pop fail, size 0");
     }
     else if (head_->first == head_->last -1 )   {
      if(head_ == tail_)   {
        delete head_;
        head_ = nullptr;
        tail_ = nullptr;
      }
      else   {
        Item* temp = head_;
        head_ = head_->next;
        head_->prev = nullptr;
        delete temp;
        head_->first =  0;
      }
     }
     else   {
        //head_->val[head_->first] = "";
        head_->first++;
     }
     size_--;

}


void ULListStr::pop_back(){
  if(size_ == 0) {
    throw std::runtime_error("popback fail, size 0");
  }
  else if (tail_->first == tail_->last -1 ) { //case for if only single element remains
    if (head_ == tail_ )   {
      delete tail_;
      head_ = nullptr;
      tail_ = nullptr;
    }
    else {
      Item* temp = tail_;
      tail_ = tail_->prev;
      tail_->next = nullptr;
      delete temp;
    }
  }
  else   {
    tail_->last--;
  }
  size_--;

}
