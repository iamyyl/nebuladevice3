#pragma once
//------------------------------------------------------------------------------
/**
    @class Toolki::N3ViewerApp
    
    Application class for the remote-controllable Nebula3 standard viewer.
    
    (C) 2009 Radon Labs GmbH
*/
#include "apprender/viewerapplication.h"
#include "resources/resourceid.h"
#include "graphics/modelentity.h"
#include "graphics/globallightentity.h"

//------------------------------------------------------------------------------
namespace Editor
{
class N3ViewerApp : public App::ViewerApplication
{
	__DeclareSingleton(N3ViewerApp);
public:
	/// constructor
	N3ViewerApp();
	/// destructor
	virtual ~N3ViewerApp();
	/// open the application
	virtual bool Open();
	/// close the application
	virtual void Close();
	/// run the application
	virtual void Run();

	/// setup the light stage
	void SetupLights();
	/// discard lights in the scene
	void DiscardLights();
	/// load an object 
	void LoadModel(const Resources::ResourceId& resId);
	/// apply skin to character model of specified ressource ID
	void LoadSkin(const Resources::ResourceId& modelResId, const Resources::ResourceId& skinResId);
	/// remove skin from character model of specified ressource ID
	void RemoveSkin(const Resources::ResourceId& modelResId, const Resources::ResourceId& skinResId);
	/// replace animation of character model of specified ressource ID
	void LoadAnimation(const Resources::ResourceId& modelResId, const Resources::ResourceId& animResId);
	/// replace variation of character model of specified ressource ID
	void LoadVariation(const Resources::ResourceId& modelResId, const Resources::ResourceId& varResId);
	/// clear models in the scene
	void DiscardModels();
	/// set windows 
	void SetParentWindow(void* h);
	/// set current window handle
	void SetCurrentWindow(void* h);

protected:
	/// called to configure display (sets shd: assign to home directory, not project directory)
	virtual void OnConfigureDisplay();
	/// process input (called before rendering)
	virtual void OnProcessInput();
	/// handle per-frame stuff
	virtual void OnUpdateFrame();
	/// query the project root path from the registry (if Radon Labs Toolkit is installed)
	Util::String QueryProjectPathFromRegistry() const;

	/// perform setup from command line args
	void SetupSceneFromCmdLineArgs();

	Util::Array<Ptr<Graphics::ModelEntity> > modelEntities;
	Ptr<Graphics::GlobalLightEntity> globalLightEntity;
	void* m_parentHwnd;
	void* m_currenthwnd;
	Ptr<Models::ModelServer> modelServer;
};
}
//------------------------------------------------------------------------------
