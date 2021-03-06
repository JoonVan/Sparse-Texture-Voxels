#pragma once

#include "../Utils.h"
#include "Mesh.h"
#include "MeshLibrary.h"
#include "Lighting.h"
#include "Object.h"
#include "Scene.h"
#include "ShaderLibrary.h"
#include "SceneLibrary.h"

class CoreEngine
{
private:

    MeshLibrary meshLibrary;
    ShaderLibrary shaderLibrary;
    RenderData renderData;
    SceneLibrary sceneLibrary;
    

public:

    Scene* scene;

    void begin(std::string filename)
    {
        shaderLibrary.begin();
        renderData.begin();
        meshLibrary.begin();
        sceneLibrary.begin();

        scene = sceneLibrary.addScene(renderData, meshLibrary, shaderLibrary, filename, filename);

        meshLibrary.commitToGL(renderData);
        scene->commitToGL();
        renderData.commitToGL();
    }

    void updateScene()
    {
        scene->display(renderData);
    }
    void display()
    {
        renderData.display();
    }
};
    
