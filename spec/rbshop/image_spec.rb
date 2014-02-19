require 'spec_helper'

describe RBShop::Image do
  let(:img) { described_class.load fixture_path('stevelikesyou.jpg')}

  it 'exists' do
    expect( described_class ).to eq(RBShop::Image)
  end

  context ".load" do
    it 'loads an image' do
      expect( img ).to be_a(described_class)
    end

    it 'returns nil for an invalid image' do
      invalid_img = described_class.load fixture_path('sir-not-appearing-in-this-test.jpg')
      expect( invalid_img ).to be_nil
    end
  end

  context 'getters' do
    describe '#width' do
      it 'has the correct value' do
        expect( img.width ).to eq(500)
      end
    end

    describe '#height' do
      it 'has the correct value' do
        expect( img.height ).to eq(500)
      end
    end
  end
end
