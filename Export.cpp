#include "pch.h"
#include "Export.h"

//===================tga
TGAImage* tga_create(int w, int h, int bpp) {
	return  new TGAImage(w, h, bpp);
}

bool read_tga_file(TGAImage* image, const char* filename) {
	return image->read_tga_file(filename);
}
bool write_tga_file(TGAImage* image, const char* filename, bool rle) {
	return image->write_tga_file(filename, rle);
}
bool flip_horizontally(TGAImage* image) {
	return image->flip_horizontally();
}
bool flip_vertically(TGAImage* image) {
	return image->flip_vertically();
}
bool scale(TGAImage* image, int w, int h) {
	return image->scale(w, h);
}
TGAColor* get(TGAImage* image, int x, int y) {
	return new TGAColor(image->get(x, y));
}
bool set(TGAImage* image, int x, int y, TGAColor* c) {
	return image->set(x, y, *c);
}
int get_width(TGAImage* image) {
	return image->get_width();
}
int get_height(TGAImage* image) {
	return image->get_height();
}
int get_bytespp(TGAImage* image) {
	return image->get_bytespp();
}
unsigned char* buffer(TGAImage* image) {
	return image->buffer();
}
void clear(TGAImage* image) {
	image->clear();
}

//===================modle

Model* model_create(const char* filename) {
	return new Model(filename);
}
int nverts(Model* model) {
	return model->nverts();
}
int nfaces(Model* model) {
	return model->nfaces();
}
Vec3f* vert(Model* model, int i) {
	return new Vec3f(model->vert(i));
}
int* face(Model* model, int idx, int* size) {
	std::vector<int> v = model->face(idx);
	*size=v.size();
	int* result = (int*)malloc(sizeof(int) * (*size));
	std::copy(v.begin(), v.end(), result);
	return result;
}
