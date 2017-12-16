Pod::Spec.new do |s|
    s.name              = 'IMbeeCore'
    s.version           = '0.9.7f'
    s.summary           = 'IMbee Core SDK'
    s.homepage          = 'https://docs.imbee.es/ios/imbee-core/'

    s.author            = { 'IMbee' => 'info@imbeemessenger.com' }
    s.license           = { :type => 'Apache-2.0', :file => 'LICENSE' }

    s.platform          = :ios
    s.source            = { :http => "https://s3.amazonaws.com/imbee/SDK/iOS/IMbeeCore-#{s.version.to_s}.zip" }

    s.ios.deployment_target = '9.0'
    s.ios.vendored_frameworks = 'IMbeeCore.framework'

    s.ios.dependency 'sqlite3', '~> 3.21'
    s.ios.dependency 'SSZipArchive', '~> 2.1'
    s.ios.dependency 'XMPPFramework', '~> 3.7.0imbee'
end
