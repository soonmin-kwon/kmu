#ifndef KMUCS_GRAPHICS_VEC_HPP
#define KMUCS_GRAPHICS_VEC_HPP

#include <iostream>
#include <algorithm>

namespace kmuvcl {
  namespace math {

    template <unsigned int N, typename T>
    class vec
    {
    public:
      vec()
      {
        set_to_zero();
      }

      vec(const T elem)
      {
        
	       std::fill(val, val+N, elem);
      }

      vec(const T s, const T t) : vec()
      {
        
	       val[0] = s;
	       val[1] = t;
      }

      vec(const T s, const T t, const T u) : vec()
      {
       
	       val[0] = s;
	       val[1] = t;
	       val[2] = u;
      }

      vec(const T s, const T t, const T u, const T v) : vec()
      {
       
	       val[0] = s;
	       val[1] = t;
	       val[2] = u;
	       val[3] = v;
      }

      vec(const vec<N, T>& other)
      {
        
	       std::copy(other.val, other.val + N, val);
      }

      vec& operator= (const vec<N, T>& other)
      {
       
	      for(int i = 0; i < N; ++i)
	      {
		        val[i] = other.val[i];
	      }
        return  *this;
      }

      T& operator()(unsigned int i)
      {
	     
        return  val[i];
      }

      const T& operator()(unsigned int i) const
      {
	    
        return  val[i];
      }

      // type casting operators
      operator const T* () const
      {
        return  val;
      }

      operator T* ()
      {
        return  val;
      }

      vec& operator+=(const vec<N, T>& other)
      {
        
	      for(int i = 0; i < N; ++i)
	      {
		       val[i] += other.val[i];
	      }
        return *this;
      }

      vec& operator-=(const vec<N, T>& other)
      {
        
	      for(int i = 0; i < N; ++i)
	      {
		       val[i] -= other.val[i];
	      }
        return *this;
      }

      void set_to_zero()
      {
       
	      std::fill(val, val+N, 0);
      }

    protected:
      T val[N];
    };

    // typedef
    typedef vec<2, float>   vec2f;
    typedef vec<2, double>  vec2d;
    typedef vec<2, int>     vec2i;

    typedef vec<3, float>   vec3f;
    typedef vec<3, double>  vec3d;
    typedef vec<3, int>     vec3i;
    
    typedef vec<4, float>   vec4f;
    typedef vec<4, double>  vec4d;
    typedef vec<4, int>     vec4i;


  } // namespace math
} // namespace kmuvcl


#include "operator.hpp"
#include "transform.hpp"
#endif // KMUCS_GRAPHICS_VEC_HPP
