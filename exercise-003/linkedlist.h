#ifndef MY_LINKED_LIST
#define MY_LINKED_LIST

#include <fmt/format.h>
#include <functional>
#include <string>

struct LinkedListNode
{

  LinkedListNode(const std::string &name)
    : m_name(name), pNext(nullptr)
  {

  }
  LinkedListNode()
    : LinkedListNode("")
  {
  }
  ~LinkedListNode()
  {
    fmt::print("    -> Killing {}\n", m_name);
  }
  /* Print the Name */
  void print()
  {
    fmt::print("My Name is {}\n", m_name);
  }
  LinkedListNode *pNext;
  std::string m_name;
};


class LinkedList
{
public:
  LinkedList()
    : m_head(nullptr), m_tail(nullptr)
  {
  }
  ~LinkedList();
  /**
   * Insert an element at the tail of the list
   */
  bool insert_tail(LinkedListNode *node);
  /**
   * Insert an element at the head of the list
   */
  bool insert_head(LinkedListNode *node);

  /**
   * Insert an element after a given location
   *
   * loc the element after we want to insert the node
   */
  bool insert_after(LinkedListNode *loc, LinkedListNode *node);

  /**
   * Insert an element before a given location
   *
   * loc the element we want to insert the node in foront of
   */
  bool insert_before(LinkedListNode *loc, LinkedListNode *node);

  /**
   * delete an element from the list
   */
  bool remove(LinkedListNode *node);

  /**
   * get the amount of elements in the list
   */
  size_t size();
  /**
   * Traverse the list and call the operation
   */
  void traverse(std::function<void(const std::string &)> func);
  void traverse(std::function<void(LinkedListNode *node)> func);

private:
  LinkedListNode *m_head;
  LinkedListNode *m_tail;
};


#endif