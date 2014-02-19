module RBShop
  # An +Image+ is an abstraction of any image file that
  # GraphicsMagick can load.

  class Image
    # Loads an image from a file.
    #
    # +nil+ is returned if the file is an invalid image
    #
    #   img = Image.load('cthulhu.jpg')
    #   # => <RBShop::Image:0xd34db33f>
    def self.load(path); end
  end
end
