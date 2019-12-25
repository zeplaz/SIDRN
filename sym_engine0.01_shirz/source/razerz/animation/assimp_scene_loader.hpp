#pragma once
const int WEIGHTS_PER_VERTEX = 4;

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "animated_mesh.hpp"



class animated_mesh_loader{

  private :
  std::vector<animated_mesh> meshes;
  void recursive_processing(aiNode* node, const aiScene* scene);
  void process_mesh(aiMesh* mesh const aiScene* scene);
  unsigned int load_texture(const char* path);
  public :

  ~animated_mesh_loader();
  std::vector<animated_mesh*>&get_meshes();
  std::vector<animated_mesh> move_meshes();

};
