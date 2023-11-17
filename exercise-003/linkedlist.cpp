#include "linkedlist.h"

LinkedList::~LinkedList()
{
  while( size() != 0 ){
    auto tmp = m_head;
    if(remove(tmp)){
      delete tmp;
    }
  }
}

bool LinkedList::insert_tail(LinkedListNode *node)
{
  bool ret = false;
  if (nullptr == node) {
    return ret;
  }
  if (nullptr == m_tail ) {
    /* empty list*/
    m_head = node;
    m_tail = node;
  } else {
    return insert_after(m_tail, node);
  }
  return ret;
}

bool LinkedList::insert_head(LinkedListNode *node)
{
  bool ret = false;
  if (nullptr == node) {
    return ret;
  }
  if (nullptr == m_head) {
    /* empty list*/
    m_head = node;
    m_tail = node;
  } else {
    ret = insert_before(m_head, node);
  }
  return ret;
}

bool LinkedList::insert_after(LinkedListNode *loc, LinkedListNode *node)
{
  bool ret = false;
  if ((nullptr == loc) || (nullptr == node)) {
    return ret;
  }
  if (nullptr == loc->pNext) {
    /*End of the list*/
    m_tail = node;
  }
  loc->pNext = node;
  ret = true;
  return ret;
}

bool LinkedList::insert_before(LinkedListNode *loc, LinkedListNode *node)
{
  bool ret = false;
  if ((nullptr == loc) || (nullptr == node)) {
    return ret;
  }
  if (m_head == loc) {
    node->pNext = m_head;
    m_head = node;
    ret = true;
  } else {
    auto tmp = m_head;
    while (tmp) {
      if (tmp->pNext == loc) {
        break;
      }
      tmp = tmp->pNext;
    }
    if (tmp->pNext == loc) {
      node->pNext = loc;
      tmp->pNext = loc;
      ret = true;
    } else {
      ret = false;
    }
  }
  return ret;
}

bool LinkedList::remove(LinkedListNode *node)
{
  bool ret = false;
  auto tmp = m_head;
  if (m_head == nullptr || m_tail == nullptr)
  {
    fmt::println("Can not remove element from empty list");
    return false;
  }
  if (m_head == node)
  {
    fmt::println("Remove head of the list");
    m_head = tmp->pNext;
    if(tmp == m_tail)
    {
      m_head = nullptr;
      m_tail = nullptr;
    }
    return true;
  }
  else
  {
    while (tmp)
    {
      if (tmp->pNext == node)
      {
        if (m_tail == node)
        {
          fmt::println("Removing the tail of the list");
          m_tail = tmp;
        } 
        return true;
      }
      tmp = tmp->pNext;
    }
  }

  if (tmp->pNext == node) {
    tmp->pNext = tmp->pNext->pNext;
    ret = true;
  } else {
    /* Element not found */
    ret = false;
  }
  return ret;
}

size_t LinkedList::size()
{
  size_t count = 0;
  /* using a lambda to count objects in the list*/
  traverse([&count](LinkedListNode *node) { count++; });
  return count;
}


void LinkedList::traverse(std::function<void(const std::string &)> func)
{
  traverse([&](LinkedListNode *node) { func(node->m_name); });
}

void LinkedList::traverse(std::function<void(LinkedListNode *node)> func)
{
  if(m_head == nullptr|| m_tail==nullptr)
  {
    return;
  }
  for (auto tmp = m_head; tmp != nullptr; tmp = tmp->pNext) {
    func(tmp);
  }
}