#include "image.h"

#define VARIABLE_PARAMETERS -1

MagickWand *
rbshop_img_get(VALUE obj)
{
  MagickWand *wand;
  Data_Get_Struct(
      obj,              // Ruby Object
      MagickWand,       // What is the C type?
      wand              // Where do I set it?
  );
  return wand;
}

void
rbshop_img_free(MagickWand *wand)
{
  DestroyMagickWand(wand);
}

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

  // RBShop::Image#width
  rb_define_method(
      RBShopImageClass,
      "width",
      rbshop_img_get_width,
      0
  );

  // RBShop::Image#height
  rb_define_method(
      RBShopImageClass,
      "height",
      rbshop_img_get_height,
      0
  );

  // RBShop::Image#charcoal(radius=1)
  rb_define_method(
      RBShopImageClass,
      "charcoal",
      rbshop_img_charcoal,
      VARIABLE_PARAMETERS
  );

  // RBShop::Image#save(destination)
  rb_define_method(
      RBShopImageClass,
      "save",
      rbshop_img_save,
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
      rbshop_img_free,  // Free up the memory
      wand              // What Ruby is wrapping
  );

  return self;
}

// RBShop::Image#width
VALUE
rbshop_img_get_width(VALUE self)
{
  MagickWand *wand = rbshop_img_get(self);
  unsigned long width = MagickGetImageWidth(wand);
  return INT2NUM(width);
}

// RBShop::Image#height
VALUE
rbshop_img_get_height(VALUE self)
{
  MagickWand *wand = rbshop_img_get(self);
  unsigned long height = MagickGetImageHeight(wand);
  return INT2NUM(height);
}

// RBShop::Image#charcoal
VALUE
rbshop_img_charcoal(
    int argc, VALUE *argv, VALUE self)
{
  MagickWand *wand = rbshop_img_get(self);
  VALUE r_radius;
  VALUE r_sigma;
  rb_scan_args(
      argc,             // The count
      argv,             // The values
      "02",             // 0 required args, 2 optional args
      &r_radius,        // The variables where the arguments
      &r_sigma          // go into
  );

  double radius = 0;
  double sigma = 0;

  if( RTEST(r_radius) )
  {
    Check_Type(r_radius, T_FLOAT);
    radius = NUM2DBL(r_radius);
  } else {
    radius = 1; 
  }

  if( RTEST(r_sigma) )
  {
    Check_Type(r_sigma, T_FLOAT);
    sigma = NUM2DBL(r_sigma);
  } else {
    sigma = radius / 2; 
  }
   
  MagickCharcoalImage(wand, radius, sigma);
  return self;
}

VALUE 
rbshop_img_save(VALUE self, VALUE r_destination)
{
  MagickWand *wand = rbshop_img_get(self);
  char *destination = StringValueCStr(r_destination); 

  MagickWriteImage(wand, destination);
  return self;
}
