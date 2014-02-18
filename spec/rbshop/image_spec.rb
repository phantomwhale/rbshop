require 'spec_helper'

describe RBShop::Image do
  it 'exists' do
    expect( described_class ).to eq(RBShop::Image)
  end

  context ".load" do
    it 'loads an image' do
      img = described_class.load fixture_path('lena.jpg')
      expect( img ).to be_a(described_class)
    end
  end
end
