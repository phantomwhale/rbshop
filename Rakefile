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
