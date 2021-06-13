#pragma once

#include <Hakool\Core\Graphics\hkIProgram.h>

#include <Hakool\GraphicsOpenGL\hkGraphicsOpenGLPrerequisites.h>

namespace hk
{
  /**
  * Provides a common interface for extended programs.
  */
  class ProgramOpenGL :
    public IProgram
  {
  public:

    /**
    * Constructor.
    */
    ProgramOpenGL();

    /**
    * Destructor.
    */
    virtual ~ProgramOpenGL();

    /**
    * Initialize the program.
    *
    * @param _graphicComponent Reference to the graphic component.
    *
    * @return Operation result.
    */
    virtual eRESULT
    init(GraphicComponent* _pGraphicComponent) override;

    /**
     * Create the program with the given shader.
     *
     * @param _fragment The key of the fragment shader.
     * @param _vertex The key of the vertex shader.
     * @param _pResourceManager The pointer to the resource manager.
     *
     * @return Operation result.
     */
    virtual eRESULT
    create
    (
      const String& _fragment,
      const String& _vertex,
      ResourceManager* _pResourceManager
    ) override;

    /**
    * Get the pointer to the wrapped API's shader.
    *
    * @return The pointer to the wrapped API's shader.
    */
    virtual void*
    getProgramPtr() override;

    /**
    * Check if the program is ready to be used.
    *
    * @return True if the program is ready, otherwise returns false.
    */
    virtual bool
    isReady() override;    

    /**
    * Safely destroys this program.
    */
    virtual void
    destroy() override;

  private:

    /**
    * Indicates if the progam is ready to be used.
    */
    bool
    _m_isReady;

    /**
    * OpenGL program identifier.
    */
    uint32
    _m_programId;

  };
}