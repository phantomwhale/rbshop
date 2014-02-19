#include "ruby.h"

#include <wand/magick_wand.h>

void rbshop_define_image_class();

// RBShop::Image.load(path)
VALUE rbshop_img_load(VALUE klass, VALUE path);
