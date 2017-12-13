Pod::Spec.new do |s|
    s.name              = 'IMbeeCore'
    s.version           = '0.2.17e'
    s.summary           = 'IMbee Core SDK'
    s.homepage          = 'https://docs.imbee.es/ios/imbee-core/'

    s.author            = { 'IMbee' => 'info@imbeemessenger.com' }
    s.license           = { :type => 'Apache-2.0', :file => 'LICENSE' }

    s.platform          = :ios
    s.source            = { :http => "https://s3.amazonaws.com/imbee/SDK/iOS/IMbeeCore-0.9.7d.zip" }

    s.ios.deployment_target = '9.0'
    s.ios.vendored_frameworks = 'IMbeeUI.framework'

    #s.ios.dependency 'CocoaAsyncSocket', '~> 7.6'
    #s.ios.dependency 'CocoaLumberjack', '~> 3.3'
    #s.ios.dependency 'CocoaLumberjack/Swift'

    s.ios.dependency 'Haneke', '~> 1.0'
    s.ios.dependency 'KAProgressLabel', '~> 3.3'
    #s.ios.dependency 'sqlite3', '~> 3.21'
    #s.ios.dependency 'SSZipArchive', '~> 2.1'
    s.ios.dependency 'TTTAttributedLabel', '~> 2.0'
    #s.ios.dependency 'XMPPFramework', '~> 3.7' #:git => 'https://github.com/robbiehanson/XMPPFramework.git', :commit => '75728a4'
end
