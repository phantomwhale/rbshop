require 'spec_helper'

describe RBShop::Image do
  it 'exists' do
    expect( described_class ).to eq(RBShop::Image)
  end

  context ".load" do
    it 'loads an image' do
      img = described_class.load fixture_path('stevelikesyou.jpg')
      expect( img ).to be_a(described_class)
    end

    it 'returns nil for an invalid image' do
      img = described_class.load fixture_path('sir-not-appearing-in-this-test.jpg')
      expect( img ).to be_nil
    end
  end
end
