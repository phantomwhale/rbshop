require "bundler/gem_tasks"

# Compile tasks
require "rake/extensiontask"

Rake::ExtensionTask.new("rbshop") do |ext|
  ext.lib_dir = "lib/rbshop"
end

# Specs
require "rspec/core/rake_task"

RSpec::Core::RakeTask.new("spec")

task :default => [:clean, :compile, :spec]

# Console
task :console do
  require 'irb'
  require 'irb/completion'
  require 'rbshop'

  include RBShop

  def img 
    @img ||= Image.load('spec/fixtures/cthulhu.jpg')
  end

  def preview 
    img.save('/tmp/imagetmp.jpg')
    `gnome-open /tmp/imagetmp.jpg`
  end

  def reload!
    @img = nil
  end

  ARGV.clear
  IRB.start
end
