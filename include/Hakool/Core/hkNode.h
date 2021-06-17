#pragma once

#include <Hakool\Utils\hkUtilitiesUtilities.h>
#include <Hakool\Utils\hkLogger.h>

namespace hk
{
  /**
  * Provides functionally that simulates a hierarchical tree structure to 
  * extended classes.
  */
  template<typename T>
  class Node
  {
  public:

    /**
    * Constructor.
    */
    Node();

    /**
    * Constructor.
    * 
    * @param _name The name of this node.
    */
    Node(const String& _name);

    /**
    * Constructor.
    * 
    * @param _name The name of this node.
    * @param _parent Parent node.
    */
    Node(const String& _name, T& _parent);

    /**
    * Destructor.
    */
    virtual ~Node();

    /**
    * Set the name of this node.
    * 
    * @param _newName The new name of this node.
    * 
    * @return Operation result.
    * 
    * * kSuccess: The node is renamed.
    * * kObjectAlreadyExists: The parent already has a node with this name.
    */
    eRESULT
    setName(const String& _newName);
    
    /**
    * Get the name of this node.
    * 
    * @return The name of this node.
    */
    const String&
    getName() const;

    /**
    * Add a new child to this node.
    *
    * Every child should have a unique name. The child will be detached from
    * its current parent, if it has one.
    *
    * @param _child Node.
    *
    * @return Operation result:
    *
    * * kSuccess: The child was added successfully.
    * * kObjectAlreadyExists: This node already has a node with the same name, 
    * the node wasn't added.
    * * kFail: A node cannot be a child of itself.
    */
    eRESULT
    addChild(T& _child);

    /**
    * Get a child.
    * 
    * @param _name The name of the child.
    * 
    * @return Child.
    */
    T&
    getChild(const String& _name) const;    

    /**
    * Removes a child from this node.
    *
    * @param _name The name of the child.
    */
    void
    removeChild(const String& _name);

    /**
    * Check if this node has a child with the specified name.
    * 
    * @param _name The name of the child.
    * 
    * @return True if the child exists, otherwise returns false.
    */
    bool
    hasChild(const String& _name) const;

    /**
    * Get the parent of this node.
    *
    * @return Parent node.
    */
    T&
    getParent() const;

    /**
    * Check if this node has a parent.
    * 
    * @returns True if this node has a parent, otherwise returns false.
    */
    bool
    hasParent() const;

    /**
    * Remove this node from its current parent.
    */
    void
    removeFromParent();

  protected:

    /**
    * List of children.
    */
    Map<String, T*>
    _m_hChildren;

  private:

    /**
    * A node should be unique.
    */
    Node(Node&&) = delete;

    /**
    * A node should be unique.
    */
    Node&
    operator=(Node&&) = delete;

    /**
    * A node should be unique.
    */
    Node&
    operator=(const Node&&) = delete;

    /**
    * Pointer to the parent of this node.
    */
    T*
    _m_pParent;

    /**
    * The name of this node.
    */
    String
    _m_name;
  };

  template<typename T>
  inline Node<T>::Node() :
    _m_hChildren(),
    _m_name(""),
    _m_pParent(nullptr)
  {
    // Intentionally blank
    return;
  }

  template<typename T>
  inline Node<T>::Node(const String& _name) :
    _m_hChildren(),
    _m_name(_name),
    _m_pParent(nullptr)
  {
    // Intentionally blank
    return;
  }

  template<typename T>
  inline Node<T>::Node(const String& _name, T& _parent) :
    _m_hChildren(),
    _m_name(_name),
    _m_pParent(nullptr)
  {
    Node* pParentNode = static_cast<Node*>(&_parent);
    pParentNode->addChild(reinterpret_cast<T&>(*this));

    return;
  }

  template<typename T>
  inline Node<T>::~Node()
  {
    _m_pParent = nullptr;
    return;
  }

  template<typename T>
  inline eRESULT 
  Node<T>::setName(const String& _newName)
  {
    if (_m_name == _newName)
    {
      return eRESULT::kSuccess;
    }

    if (_m_pParent == nullptr)
    {
      _m_name = _newName;
      return eRESULT::kSuccess;
    }

    Node* pParentNode = static_cast<Node*>(_m_pParent);
    if(pParentNode->hasChild(_newName))
    {
      return eRESULT::kObjectAlreadyExists;
    }

    pParentNode->removeChild(_m_name);
    _m_name = _newName;
    pParentNode->addChild(reinterpret_cast<T&>(*this));

    return eRESULT::kSuccess;
  }

  template<typename T>
  inline const String& 
  Node<T>::getName() const
  {
    return _m_name;
  }

  template<typename T>
  inline eRESULT 
  Node<T>::addChild(T& _child)
  {
    Node* pChildNode = reinterpret_cast<Node*>(&_child);
    if (hasChild(pChildNode->_m_name)) 
    {
      return eRESULT::kObjectAlreadyExists;
    }

    if (&_child == this) 
    {
      return eRESULT::kFail;
    }

    pChildNode->removeFromParent();

    _m_hChildren.insert
    (
      Map<String, T*>::value_type(pChildNode->_m_name, &_child)
    );

    pChildNode->_m_pParent = reinterpret_cast<T*>(this);

    return eRESULT::kSuccess;
  }

  template<typename T>
  inline T& 
  Node<T>::getChild(const String& _name) const
  {
    if (!hasChild(_name))
    {
      throw "| Node | Node: " + _m_name + " doesn't has a child : " + _name + ".";
    }

    return *(_m_hChildren.find(_name)->second);    
  }

  template<typename T>
  inline void 
  Node<T>::removeChild(const String& _name)
  {
    if (!hasChild(_name))
    {
      return;
    }

    T* pChild = _m_hChildren.find(_name)->second;    
    _m_hChildren.erase(_name);

    Node* pChildNode = reinterpret_cast<Node*>(pChild);
    pChildNode->removeFromParent();

    return;
  }

  template<typename T>
  inline bool 
  Node<T>::hasChild(const String& _name) const
  {
    return _m_hChildren.find(_name) != _m_hChildren.end();
  }

  template<typename T>
  inline T& 
  Node<T>::getParent() const
  {
    if (_m_pParent == nullptr)
    {
      throw "Node: " + _m_name + " doesn't has a parent.";
    }

    return *_m_pParent;
  }

  template<typename T>
  inline bool 
  Node<T>::hasParent() const
  {
    return _m_pParent != nullptr;
  }

  template<typename T>
  inline void Node<T>::removeFromParent()
  {
    if (!hasParent())
    {
      return;
    }

    Node* pParentNode = reinterpret_cast<Node*>(_m_pParent);
    pParentNode->removeChild(_m_name);
    _m_pParent = nullptr;

    return;
  }
}