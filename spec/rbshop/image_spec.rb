require 'spec_helper'
require 'tmpdir'

describe RBShop::Image do
  let(:img) { described_class.load fixture_path('cthulhu.jpg')}

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
        expect( img.width ).to eq(792)
      end
    end

    describe '#height' do
      it 'has the correct value' do
        expect( img.height ).to eq(612)
      end
    end
  end

  context 'filters' do
    describe '#charcoal' do
      it 'works with no arguments' do
        expect( img.charcoal ).to be_a(described_class)
      end

      it 'works with one argument' do
        expect( img.charcoal 1.0 ).to be_a(described_class)
      end

      it 'requries a float' do
        expect { img.charcoal "10" }.to raise_error
      end
    end
  end

  context 'persistance' do
    describe '#save' do
      it 'saves an image to the destination' do
        Dir.mktmpdir do |dir|
          destination = File.join(dir, "new-file.jpg")
          img.save(destination)
          expect( File.exists?(destination)).to be_true
        end
      end
    end
  end
end
