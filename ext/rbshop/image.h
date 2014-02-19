#include "ruby.h"

#include <wand/magick_wand.h>

void rbshop_define_image_class();

// RBShop::Image.load(path)
VALUE rbshop_img_load(VALUE klass, VALUE path);

// RBShop::Image#width
VALUE rbshop_img_get_width(VALUE self);

// RBShop::Image#height
VALUE rbshop_img_get_height(VALUE self);

// RBShop::Image#charcol(radius = 0)
VALUE rbshop_img_charcoal(
    int argc, VALUE *argv, VALUE self);

// RBShop::Image#save
VALUE rbshop_img_save(VALUE self, VALUE destination);
