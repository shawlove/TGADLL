#ifndef __Export__
#define __Export__

#define DllExport   __declspec( dllexport )


#ifdef __cplusplus
extern "C" {
#endif

	//tga
	DllExport TGAImage* tga_create(int w, int h, int bpp);
	DllExport bool read_tga_file(TGAImage* image, const char* filename);
	DllExport bool write_tga_file(TGAImage* image, const char* filename, bool rle = true);
	DllExport bool flip_horizontally(TGAImage* image);
	DllExport bool flip_vertically(TGAImage* image);
	DllExport bool scale(TGAImage* image, int w, int h);
	DllExport TGAColor* get(TGAImage* image, int x, int y);
	DllExport bool set(TGAImage* image, int x, int y, TGAColor* c);
	DllExport int get_width(TGAImage* image);
	DllExport int get_height(TGAImage* image);
	DllExport int get_bytespp(TGAImage* image);
	DllExport unsigned char* buffer(TGAImage* image);
	DllExport void clear(TGAImage* image);

	//modle
	DllExport Model* model_create(const char* filename);
	DllExport int nverts(Model* model);
	DllExport int nfaces(Model* model);
	DllExport Vec3f* vert(Model* model, int i);
	DllExport int* face(Model* model, int idx, int* size);

#ifdef __cplusplus
}
#endif

#endif //__Export__

