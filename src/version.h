#ifndef glfwlatency_version_h__
#define glfwlatency_version_h__

/*
 *  version:  major, minor, patch
 */
#define GLFWLATENCY_VERSION  ((0 << 20) | (7 << 8) | 56)


static inline unsigned int   GLFWLatency_get_version_major( void)
{
   return( GLFWLATENCY_VERSION >> 20);
}


static inline unsigned int   GLFWLatency_get_version_minor( void)
{
   return( (GLFWLATENCY_VERSION >> 8) & 0xFFF);
}


static inline unsigned int   GLFWLatency_get_version_patch( void)
{
   return( GLFWLATENCY_VERSION & 0xFF);
}

#endif
