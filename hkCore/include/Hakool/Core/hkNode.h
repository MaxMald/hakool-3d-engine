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
    * Get reference to the Null object.
    */
    static T&
    GetNull();

    /**
    * Check if the given GameObject is the Null object.
    */
    static bool
    IsNull(const T& _gameObject);

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
    */
    void
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
    void
    addChild(T* pChild);

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
    T*
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
    * Sets the parent of this Node.
    */
    void
    setParent(T* _pParent);

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

  protected:

    virtual void
    _onParentChanged(T* parent);

    virtual void
    _onChildAdded(T* child);

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
    * Get the Null Object.
    */
    static T*&
    _Null();

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
  inline T& 
  Node<T>::GetNull()
  {
    return *_Null();
  }

  template<typename T>
  inline bool 
  Node<T>::IsNull(const T& _gameObject)
  {
    return *_Null() == _gameObject;
  }

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
    if (pParentNode->hasChild(_name))
    {
      throw std::invalid_argument("The parent already has a node with the name: " + _name);
    }
    
    pParentNode->addChild(reinterpret_cast<T*>(this));
  }

  template<typename T>
  inline Node<T>::~Node()
  {
    _m_pParent = nullptr;
  }

  template<typename T>
  inline void 
  Node<T>::setName(const String& _newName)
  {
    if (_m_name == _newName)
    {
      return;
    }

    if (_m_pParent == nullptr)
    {
      _m_name = _newName;
      return;
    }

    Node* pParentNode = static_cast<Node*>(_m_pParent);
    if(pParentNode->hasChild(_newName))
    {
      throw std::invalid_argument("The parent already has a node with the name: " + _newName);
    }

    pParentNode->_m_hChildren.erase(_m_name);
    _m_name = _newName;
    pParentNode->_m_hChildren.insert
    (
      Map<String, T*>::value_type(_m_name, reinterpret_cast<T*>(this))
    );
    return;
  }

  template<typename T>
  inline const String& 
  Node<T>::getName() const
  {
    return _m_name;
  }

  template<typename T>
  inline void
  Node<T>::addChild(T* pChild)
  {
    Node* pChildNode = reinterpret_cast<Node*>(pChild);
    if (hasChild(pChildNode->_m_name)) 
    {
      throw std::invalid_argument("The parent already has a node with the name: " + pChildNode->_m_name);
    }

    if (pChild == this)
    {
      throw std::invalid_argument("A Node cannot be a child of itself.");
    }

    if (pChildNode->_m_pParent != nullptr)
    {
      Node* pChildParent = reinterpret_cast<Node*>(pChildNode->_m_pParent);
      if (pChildNode != nullptr)
      {
        pChildParent->_m_hChildren.erase(pChildNode->getName());
      }
    }

    _m_hChildren.insert
    (
      Map<String, T*>::value_type(pChildNode->_m_name, pChild)
    );

    pChildNode->_m_pParent = reinterpret_cast<T*>(this);
    pChildNode->_onParentChanged(reinterpret_cast<T*>(this));

    _onChildAdded(pChild);
    return;
  }

  template<typename T>
  inline T& 
  Node<T>::getChild(const String& _name) const
  {
    if (!hasChild(_name))
    {
      Logger::Error("| Node | Node: " + _m_name + " doesn't has a child : " + _name + ".");
      return *_Null();
    }

    return *(_m_hChildren.find(_name)->second);    
  }

  template<typename T>
  inline T* 
  Node<T>::removeChild(const String& _name)
  {
    if (!hasChild(_name))
    {
      return nullptr;
    }

    T* pChild = _m_hChildren.find(_name)->second;
    _m_hChildren.erase(_name);
    
    Node* pChildNode = reinterpret_cast<Node*>(pChild);
    pChildNode->_m_pParent = nullptr;
    pChildNode->_onParentChanged(nullptr);
    return pChild;
  }

  template<typename T>
  inline bool 
  Node<T>::hasChild(const String& _name) const
  {
    return _m_hChildren.find(_name) != _m_hChildren.end();
  }

  template<typename T>
  inline void 
  Node<T>::setParent(T* _pParent)
  {
    if (_m_pParent == _pParent)
    {
      return;
    }

    if (this == _pParent)
    {
      throw std::invalid_argument("A Node cannot be the parent of itself.");
    }

    if (_pParent != nullptr)
    {
      Node* pDesireParentNode = reinterpret_cast<Node*>(_pParent);
      if (pDesireParentNode->hasChild(_m_name))
      {
        throw std::invalid_argument("The parent already has a node with the name: " + _m_name);
      }

      pDesireParentNode->_m_hChildren.insert
      (
        Map<String, T*>::value_type(_m_name, reinterpret_cast<T*>(this))
      );
    }

    if (_m_pParent != nullptr)
    {
      _m_pParent->_m_hChildren.erase(_m_name);
    }

    _m_pParent = _pParent;
    _onParentChanged(_m_pParent);

    Node* pDesireParentNode = reinterpret_cast<Node*>(_pParent);
    pDesireParentNode->_onChildAdded(reinterpret_cast<T*>(this));
    return;
  }

  template<typename T>
  inline T& 
  Node<T>::getParent() const
  {
    if (_m_pParent == nullptr)
    {
      Logger::Error("Node: " + _m_name + " doesn't has a parent.");
      return *_Null();
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
  inline void 
  Node<T>::_onParentChanged(T* pParent)
  {
    // Define in concrete class.
    return;
  }

  template<typename T>
  inline void 
  Node<T>::_onChildAdded(T* pChild)
  {
    // Define in concrete class.
    return;
  }

  template<typename T>
  inline T*& 
  Node<T>::_Null()
  {
    static T* _NULL = new T("__NULL");
    return _NULL;
  }
}