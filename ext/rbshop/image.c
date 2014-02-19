#include "image.h"

VALUE RBShopImageClass = Qnil;
extern VALUE RBShopModule;

void
rbshop_define_image_class()
{
  RBShopImageClass = rb_define_class_under(
      RBShopModule, 
      "Image",
      rb_cObject
  ); 

  // RBShop::Image.load(path)
  rb_define_singleton_method(
      RBShopImageClass, 
      "load",
      rbshop_img_load,
      1
  );
}

// RBShop::Image.load(path)
VALUE 
rbshop_img_load(VALUE klass, VALUE r_path)
{
  MagickWand *wand;
  wand = NewMagickWand();

  char *path = StringValueCStr(r_path);
  if(!MagickReadImage(wand, path))
    return Qnil;

  VALUE self = Data_Wrap_Struct(
      RBShopImageClass, // RUby Class type
      0,                // Mark function (not needed)
      0,                // TODO: ruby free
      wand              // What Ruby is wrapping
  );

  return self;
}
