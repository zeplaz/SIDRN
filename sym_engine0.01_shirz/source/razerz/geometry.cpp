
#include "geometry.hpp"

#define STBI_FAILURE_USERMSG
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void Texture_gl::init_texture()
{
  glActiveTexture(GL_TEXTURE0+texture_indexUnit);
  glBindTexture(GL_TEXTURE_2D,texture_ID);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glTexImage2D(GL_TEXTURE_2D, 0, return_TextureFormat(), width, height, 0, return_TextureFormat(), GL_UNSIGNED_BYTE, image);
  stbi_image_free(image);
  glBindTexture(GL_TEXTURE_2D,0);
}

void Texture_gl::load_texture(std::string path,int force_channel)
{
  image = stbi_load(path.c_str(),&width,&height,&n,force_channel);
}

void mesh::init(wavefornt_parser2* wp, std::string res_path)
{
  wp->read_file(res_path);
  std::vector< glm::vec3 > vertices;
  std::vector< glm::vec3 > normals;
  std::vector< glm::vec2 > uvs;

  wp->return_data(vertices,uvs,normals);
  pack_mesh_vertex(vertices,normals,uvs);
}

/*mesh::mesh(std::vector<mesh_vertex>verticies)
    {
      this->m_vertices =verticies;
      //this->m_indices  =indices;
    //  this->m_textures =textures;
      inialize_indexer_VBO();
      setup_mesh_4buf();
    }

    mesh::mesh(std::vector<glm::vec3> in_position,
               std::vector<glm::vec3> in_normal,
               std::vector<glm::vec2> in_textcord)
        {
          //this->m_vertices =verticies;
        //  this->m_indices  =indices;
          //this->m_textures =textures;
          //inialize_indexer_VBO();
          index_VBO(in_position,in_textcord,in_normal,m_indices,
                    indexed_vertices,indexed_uvs,indexed_normals);
          setup_mesh_4buf();
        }*/


    void mesh::setup_mesh_4buf()
    {
      glGenVertexArrays(1,&VAO_mesh);

      glGenBuffers(1,&vertex_buf);
      glGenBuffers(1,&uv_buf);
      glGenBuffers(1,&normal_buf);
      glGenBuffers(1,&element_buf);

      glBindVertexArray(VAO_mesh);

      glBindBuffer(GL_ARRAY_BUFFER,vertex_buf);
      glBufferData(GL_ARRAY_BUFFER,indexed_vertices.size()*sizeof(glm::vec3),
                   &indexed_vertices[0],GL_STATIC_DRAW);
      glEnableVertexAttribArray(0);
      glVertexAttribPointer(
			0,                  // attribute
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);

      glBindBuffer(GL_ARRAY_BUFFER,uv_buf);
      glBufferData(GL_ARRAY_BUFFER,indexed_uvs.size()*sizeof(glm::vec2),
                   &indexed_uvs[0],GL_STATIC_DRAW);

      glEnableVertexAttribArray(1);
      glVertexAttribPointer(
			1,                                // attribute
			2,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
		);

      glBindBuffer(GL_ARRAY_BUFFER,normal_buf);
      glBufferData(GL_ARRAY_BUFFER,indexed_normals.size()*sizeof(glm::vec3),
                   &indexed_normals[0],GL_STATIC_DRAW);
      glEnableVertexAttribArray(2);
      glVertexAttribPointer(
			2,                                // attribute
			3,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
		);

      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,element_buf);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER,m_indices.size()*sizeof(unsigned int),
                  &m_indices[0],GL_STATIC_DRAW);
    }

void   mesh::setup_mesh_packed()
    {
      glGenVertexArrays(1,&VAO_mesh);
      glGenBuffers(1,&buff_mesh);
      glGenBuffers(1,&EBO);

      glBindVertexArray(VAO_mesh);

      glBindBuffer(GL_ARRAY_BUFFER,buff_mesh);

      glBufferData(GL_ARRAY_BUFFER,m_vertices.size()*sizeof(mesh_vertex),&m_vertices[0],GL_STATIC_DRAW);

      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER,m_indices.size()*sizeof(unsigned int), &m_indices[0],GL_STATIC_DRAW);

      glEnableVertexAttribArray(0);
      glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(mesh_vertex),(void*)0);

      glEnableVertexAttribArray(1);
      glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,sizeof(mesh_vertex),(void*)offsetof(mesh_vertex,v_normal));

      glEnableVertexAttribArray(2);
      glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,sizeof(mesh_vertex),(void*)offsetof(mesh_vertex,v_textcord));

      glBindVertexArray(0);

    }

    bool get_sim_vertex_index(mesh_vertex& mv_pack, std::map<mesh_vertex,unsigned int>& vertex_outindex,
                              unsigned int &result)
        {
          std::map<mesh_vertex,unsigned int>::iterator it = vertex_outindex.find(mv_pack);
          if(it ==vertex_outindex.end())
          {return false;}
          else
          {
            result= it->second;
            return true;
          }
        }
    void index_VBO_packed (std::vector<mesh_vertex> in_vec_vertex,
                	  std::vector<unsigned int> & out_indices,
                  	std::vector<glm::vec3> & out_vertices,
                  	std::vector<glm::vec2> & out_uvs,
                  	std::vector<glm::vec3> & out_normals
    )

    {
    std::map<mesh_vertex,unsigned int> vertex_outindex;
    for(unsigned int i =0; i<in_vec_vertex.size();i++)
    {

      mesh_vertex v_pack = in_vec_vertex[i];//{in_vertices[i], in_uvs[i], in_normals[i]};
      unsigned int index;
      bool found = get_sim_vertex_index(v_pack,vertex_outindex,index);
      if(found)
      {
        out_indices.push_back(index);
      } else
      {
          out_vertices.push_back( v_pack.v_position);
    			out_uvs     .push_back( v_pack.v_textcord);
    			out_normals .push_back( v_pack.v_normal);
    			unsigned int newindex = (unsigned int)out_vertices.size() - 1;
    			out_indices .push_back( newindex );
    			vertex_outindex[ v_pack ] = newindex;
      }
    }
    }

    void index_VBO(std::vector<glm::vec3> & in_vertices,
                   std::vector<glm::vec2> & in_uvs,
                   std::vector<glm::vec3> & in_normals,
                   std::vector<unsigned int> & out_indices,
                   std::vector<glm::vec3> & out_vertices,
                   std::vector<glm::vec2> & out_uvs,
                   std::vector<glm::vec3> & out_normals
    )

    {
    std::map<mesh_vertex,unsigned int> vertex_outindex;
    for(unsigned int i =0; i<in_vertices.size();i++)
    {

      mesh_vertex v_pack = {in_vertices[i],in_normals[i],in_uvs[i]};
      unsigned int index;
      bool found = get_sim_vertex_index(v_pack,vertex_outindex,index);
      if(found)
      {
        out_indices.push_back(index);
      } else
      {
          out_vertices.push_back( in_vertices[i]);
          out_uvs     .push_back( in_uvs[i]);
          out_normals .push_back( in_normals[i]);
          unsigned int newindex = (unsigned int)out_vertices.size() - 1;
          out_indices .push_back( newindex );
          vertex_outindex[ v_pack ] = newindex;
      }
    }
    }
