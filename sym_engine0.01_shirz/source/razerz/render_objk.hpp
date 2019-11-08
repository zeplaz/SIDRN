
#pragma once
#include "gl_lib_z.hpp"
#include <tuple>
typedef std::tuple<unsigned char,int,int,int,GLfloat*,GLfloat*> f_sp_tuple;

#define GET_FET_FLAGZ 0
#define GET_FET_POS_SIZE 1
#define GET_FET_COLOUR_SIZE 2
#define GET_FET_NUMVERX 3
#define GET_FET_POS_DATA 4
#define GET_FET_COLOUR_DATA 5

class render_gl
{

};

class metrealz_gl
{

};

class lightz_gl
{
  private :
  GLuint s_Program_ID;
  GLint ambientLightUinform_ID;
  GLint light_pos_uniform_ID;
  GLint lenz_pos_world_uniform_ID;

  glm::vec4 ambient_light_3Depth;
  glm::vec3 light_pos_world3Depth;
  public :

  set_shader_program(GLuint p_id)
  {
    s_Program_ID=p_id;
  }
  set_force_ambient_light(float r, float g, float b,float a)
  {
    ambient_light_3Depth[0]= r;
    ambient_light_3Depth[1]= g;
    ambient_light_3Depth[2]= b;
    ambient_light_3Depth[3]= a;
  }
  cal_gl_uniformz(GLuint prog_ID = s_Program_ID,view_lenz& active_lenz)
  {
    ambientLightUinform_ID = glGetUniformLocation(prog_ID,"u_ambient_light");
    light_pos_uniform_ID = glGetUniformLocation(prog_ID,"u_light_pos_world");
    lenz_pos_world_uniform_ID = glGetUniformLocation(prog_ID,"u_lenz_pos_world");

    glm::vec3 lenz_pos_vec = active_lenz.get_position_glm();

    glUniform3fv(lenz_pos_world_uniform_ID,1,&lenz_pos_vec[0]);
    glUniform4fv(ambientLightUinform_ID,1,&ambient_light_3Depth[0]);
    glUniform3fv(light_pos_uniform_ID,1,&light_pos_world3Depth[0]);

  }

};

//shape factory -> make object
//glVertexAttrib3f etc... (location,,000)
send_multi_data_gl()
{
  objkdata = genrator
  GLsuzeiptr current_offset;
  glGenBuffers(1,&the_big_buff_ID);
  glBindBuffer(GL_ARRAY_BUFFER,the_big_buff_ID);
  glBufferData(GL_ARRAY_BUFFER,total_size_data,0,GL_DYNAMIC_DRAW);

  glBufferSubData(GL_ARRAY_BUFFER,0,);

}

void draw_(gl_shader& in_shader, GLuint* in_buffer,int num_draw)
{
  glClear( GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  glUseProgram(in_shader.program_ID);
  //glBindBuffer(GL_ARRAY_BUFFER,*in_buffer);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,*in_buffer);
  //glUniform4f(location?,r,0.3f,0.8f,1.0f);
  glEnableVertexAttribArray(0);
  glDrawElements(GL_TRIANGLES,num_draw,GL_UNSIGNED_INT,NULL);
}

class indexable_buffer
{
  private :

  GLuint index_obj_buffer;

  GLuint* ptr_indicate_data;
  GLuint num_points;
  GLuint byte_size;
  unisgned int Indeable_ojk_ID;

  public :
  inline GLuint
  void set_indeictable(const unsigned int* data_inicez, GLuint d_size)
  {
    byte_size = d_size;
    ptr_indicate_data = data_inicez;
  }

  void index_VAO_buf_gen()
  {
    std::cout <<"indexbinding_VAO\n";
    glGenBuffers(1,&index_obj_buffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,index_obj_buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,num_points*sizeof(GLuint),indeicz,GL_DYNAMIC_DRAW);

  }
  void bind() const
  {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,index_obj_buffer);
  }
  void unbind() const
  {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
  }

};
class Basic_vertex_array_buffer

{
  private :
  unsigned int vertx_obj_ID;

  public :
  unsigned int v_buf_ID;

  ~Basic_vertex_array_buffer()
  {
    glDeleteBuffers(1,&v_buf_ID);
  }
  set_Verx_buf(const void* data,int size)
{
  glGenBuffers(1,&v_buf_ID);
  glBindBuffer(GL_ARRAY_BUFFER,v_buf_ID);
  glBufferData(GL_ARRAY_BUFFER,size,data GL_DYNAMIC_DRAW);
}
  void bind() const
  {
    glBindBuffer(GL_ARRAY_BUFFER,v_buf_ID) ;
  }
  void unbind() const
  {
    glBindBuffer(GL_ARRAY_BUFFER,0);
  }
};

class Element_array_buffer
{
  private :

  public :
  unsigned int v_buf_ID;


  set_element_v_buf(const void* data,int size)
{
  glGenBuffers1(1,&v_buf_ID);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,v_buf_ID);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,size,data GL_DYNAMIC_DRAW);
}
  void render_vertex_array(int num_vertx)
  {
    glDrawArrays(GL_TRIANGLE_FAN, 0,num_vertx);
  }
};

class vertex_array_objectcapble
{
  public :

};
  class draw_able_gl
  {
    private :
    GLuint* ptr_buffer_index_ID;
    int size;

    render_mode r_mode;

    public :

    void clear_bufferz(gl_shader& in_shader)
    {
      glUseProgram(in_shader.program_ID);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
    }

    void settup_Vertex_array_Objeck(GLuint shader_pos,GLuint shader_colour,GLuint programID, int num_arrayz, GLuint* vao_array,
      f_sp_tuple& in_fetu_tuple, GLuint* buffer_in_array);

      void gl_render_v3(view_lenz& in_lenz,gl_shader& in_shader)
      {
        if(r_mode ==render_mode::WIREFRAME)
        {
          glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
        }

        glBindVertexArray(*ptr_buffer_index_ID);
        
        in_lenz;

      }

    void render_elementz_indcatez()
    {

      if(r_mode ==render_mode::WIREFRAME)
      {
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
      }
      glBindVertexArray(*ptr_buffer_index_ID);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,index_Vr_buf_ob);
      glDrawElements(GL_TRIANGLES,size,GL_UNSIGNED_INT,NULL);
    }


    void load_gl_buffer(GLuint& buffer, f_sp_tuple& in_feturez);

    bool buffer_setup_ojkz(GLuint& vertex_bufz, GLuint& vertex_array_ojk, uint32_t positionAttributeIndex )
    {// Specify that our coordinate data is going into attribute index 0, and contains three floats per vertex

      // Generate and assign two Vertex Buffer Objects to our handle
    	glGenBuffers(1, &vertex_bufz);
      glGenVertexArrays(1, &vertex_array_ojk);
      glBindBuffer(GL_ARRAY_BUFFER, vertex_bufz);
      glBindVertexArray(vertex_array_ojk);
      //sizeof(MyVertex), BUFFER_OFFSET(0));
      glVertexAttribPointer(positionAttributeIndex, 3, GL_FLOAT, GL_FALSE, sizeof(vertex_array_ojk), BUFFER_OFFSET(0));
      glEnableVertexAttribArray(positionAttributeIndex+1,4,GL_FLOAT,GL_FALSE,sizeof(verx_colour_obk),BUFFER_OFFSET(sizeof(float)*3));

      return true;
    }
    };

    class cube_gl
    {
      private:
        GLuint* cube_indices_data;
        GLfloat* cube_vertices_data;

      public :
      GLuint gl_vertices_vao_ID = 0;
      GLuint gl_indices_vao_ID = 0;
      unsigned char cube_flagz{0b0000'0101};
      //GLuint* vertex_array_ojk;

      void set_flagz(unsigned char flags)
      {
        cube_flagz |=flags;
      }

      void set_cube(GLuint* in_cube_indices, GLfloat* in_cube_vertices, unsigned char flags)
      {
        set_flagz(flags);
        cube_indices_data  = in_cube_indices;
        cube_vertices_data = in_cube_vertices;
        glGenBuffers(1,&gl_vertices_vao_ID);
        glGenBuffers(1,&gl_indices_vao_ID);
        //select type of object...

        glBindBuffer(GL_ARRAY_BUFFER,gl_vertices_vao);

        if(cube_flagz & ATTRBUT_DYNAMIC_DRAW)
        {
          glBufferData(GL_ARRAY_BUFFER,sizeof(cube_vertices),cube_vertices,GL_DYNAMIC_DRAW);
        }
        else
        {
          glBufferData(GL_ARRAY_BUFFER,sizeof(cube_vertices),cube_vertices,GL_STATIC_DRAW);
        }
        //glBindBuffer(GL_ARRAY_BUFFER,0);
        glEnableVertexAttribArray(gl_vertices_vao);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*(pos_depth*num_vertx), BUFFER_OFFSET(0));
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*(colour_data_depth*num_vertx), BUFFER_OFFSET(sizeof(GLfloat)*pos_depth*num_vertx));

      }
    };

/*
GLuint* create_cube(GLuint* in_cube_indices, GLfloat* in_cube_vertices)
{



  return vertex_array_ojk;
}
*/
