#include <Hakool/Core/hkCameraManager.h>
#include <Hakool/Core/hkCamera.h>

namespace hk
{
  CameraManager::CameraManager() :
    _m_cameras(),
    _m_defaultCamera(0),
    _m_cameraCounter(0)
  { }

  CameraManager::~CameraManager()
  { }

  const uint32&
    CameraManager::createCamera()
  {
    Camera* pNewCamera = new Camera(++_m_cameraCounter);
    _m_cameras.insert(
      Map<uint32, Camera*>::value_type(_m_cameraCounter, pNewCamera));
    return _m_cameraCounter;
  }

  Camera&
    CameraManager::getCamera(const uint32& id) const
  {
    auto item = _m_cameras.find(id);
    if (item == _m_cameras.end())
    {
      throw new std::invalid_argument("Camera not found");
    }

    return *item->second;
  }

  void
    CameraManager::setActiveCamera(const uint32& id)
  {
    auto item = _m_cameras.find(id);
    if (item == _m_cameras.end())
    {
      throw new std::invalid_argument("Camera not found");
    }

    _m_pActiveCamera = item->second;
  }

  Camera const *
    CameraManager::getActiveCamera() const
  {
    if (_m_pActiveCamera == nullptr)
    {
      return &_m_defaultCamera;
    }
    return _m_pActiveCamera;
  }

  void
    CameraManager::destroyCamera(const uint32& id)
  {
    auto item = _m_cameras.find(id);
    if (item == _m_cameras.end())
    {
      throw new std::invalid_argument("Camera not found");
    }

    if (_m_pActiveCamera->getCameraId() == id)
    {
      _m_pActiveCamera = nullptr;
    }

    delete item->second;
    _m_cameras.erase(id);
  }

  void
    CameraManager::clearCameras()
  {
    for (auto item : _m_cameras)
    {
      delete item.second;
    }
    _m_cameras.clear();
  }

  void
    CameraManager::destroy()
  {
    clearCameras();
  }
}