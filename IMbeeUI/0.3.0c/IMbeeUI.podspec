Pod::Spec.new do |s|
    s.name              = 'IMbeeUI'
    s.version           = '0.3.0c'
    s.summary           = 'IMbee Core SDK'
    s.homepage          = 'https://docs.imbee.es/ios/imbee-ui/'

    s.author            = { 'IMbee' => 'info@imbeemessenger.com' }
    s.license           = { :type => 'Apache-2.0', :file => 'LICENSE' }

    s.platform          = :ios
    s.source            = { :http => "https://s3.amazonaws.com/imbee/SDK/iOS/IMbeeUI-0.3.0a.zip" }

    s.ios.deployment_target = '9.0'
    s.ios.vendored_frameworks = 'IMbeeUI.framework'
    s.ios.dependency 'Haneke', '~> 1.0'
    s.ios.dependency 'KAProgressLabel', '~> 3.3'
    s.ios.dependency 'TTTAttributedLabel', '~> 2.0'
    s.ios.dependency 'URLEmbeddedView', '0.11.0'
end

