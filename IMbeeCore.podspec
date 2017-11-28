Pod::Spec.new do |m|

  version = '0.9.7b'

  m.name    = 'IMbeeCore'
  m.version = version

  m.summary           = 'IMbee Core SDK'
  m.description       = 'IMbee Core SDK'
  m.homepage          = 'https://docs.imbee.es/ios/imbee-core/'
  m.author            = { 'IMbee' => 'info@imbeemessenger.com' }
  m.documentation_url = 'https://docs.imbee.es/ios/imbee-core/'

  m.source = {
    :http => "https://s3.amazonaws.com/imbee/SDK/iOS/IMbeeCore.framework.zip"
  }

  m.platform              = :ios
  m.ios.deployment_target = '9.0'

  m.requires_arc = true

  m.ios.vendored_frameworks = 'IMbee/IMbeeCore.framework'
  m.module_name = 'IMbeeCore'

end
