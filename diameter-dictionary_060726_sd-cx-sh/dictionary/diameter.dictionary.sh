<message>
<command = UserDataRequest>
<command-flags = request proxyable null null >
<cmd-code = 306 >
<protocol-version = 1 >
</command>
<avp>
    <avp-name = SessionId type = OctetString >
    <avp-code = 263 encrypt = yes multiple = no >
    <avp-flags = null mandatory null >
</avp>
<avp>
    <avp-name = DRMP type = Enumerated >
    <avp-code = 301 encrypt = no multiple = no >
    <avp-flags = null null null >
    <enum>
        < name = PRIORITY_0 code = 0 >
        < name = PRIORITY_1 code = 1 >
        < name = PRIORITY_2 code = 2 >
        < name = PRIORITY_3 code = 3 >
        < name = PRIORITY_4 code = 4 >
        < name = PRIORITY_5 code = 5 >
        < name = PRIORITY_6 code = 6 >
        < name = PRIORITY_7 code = 7 >
        < name = PRIORITY_8 code = 8 >
        < name = PRIORITY_9 code = 9 >
        < name = PRIORITY_10 code = 10 >
        < name = PRIORITY_11 code = 11 >
        < name = PRIORITY_12 code = 12 >
        < name = PRIORITY_13 code = 13 >
        < name = PRIORITY_14 code = 14 >
        < name = PRIORITY_15 code = 15 >
    </enum>
</avp>
<grouped = VendorSpecificApplicationId multiple = no >
    <grouped-avp-code = 260 encrypt = no >
    <grouped-avp-flags = null mandatory null >
</grouped>
<avp>
    <avp-name = AuthSessionState type = Enumerated >
    <avp-code = 277 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
    <enum>
        < name = STATE_MAINTAINED code = 0 >
        < name = NO_STATE_MAINTAINED code = 1 >
    </enum>
</avp>
<avp>
    <avp-name = OriginHost type = OctetString >
    <avp-code = 264 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<avp>
    <avp-name = OriginRealm type = OctetString >
    <avp-code = 296 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<avp>
    <avp-name = DestinationHost type = OctetString >
    <avp-code = 293 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<avp>
    <avp-name = DestinationRealm type = OctetString >
    <avp-code = 283 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<grouped = SupportedFeatures multiple = yes >
    <grouped-avp-code = 628 encrypt = no >
    <grouped-avp-flags = vendor null null >
    <grouped-vendor-id = 10415 >
</grouped>
<grouped = UserIdentity multiple = no >
    <grouped-avp-code = 700 encrypt = no >
    <grouped-avp-flags = vendor mandatory null >
    <grouped-vendor-id = 10415 >
</grouped>
<avp>
    <avp-name = WildcardedPublicIdentity type = OctetString >
    <avp-code = 634 encrypt = no multiple = no >
    <avp-flags = vendor null null >
    <vendor-id = 10415 >
</avp>
<avp>
    <avp-name = WildcardedIMPU type = OctetString >
    <avp-code = 636 encrypt = no multiple = no >
    <avp-flags = vendor null null >
    <vendor-id = 10415 >
</avp>
<avp>
    <avp-name = ServerName type = OctetString >
    <avp-code = 602 encrypt = no multiple = no >
    <avp-flags = vendor mandatory null >
    <vendor-id = 10415 >
</avp>
<avp>
    <avp-name = ServiceIndication type = OctetString >
    <avp-code = 704 encrypt = no multiple = yes >
    <avp-flags = vendor mandatory null >
    <vendor-id = 10415 >
</avp>
<avp>
    <avp-name = DataReference type = Enumerated >
    <avp-code = 703 encrypt = no multiple = yes >
    <avp-flags = vendor mandatory null >
    <vendor-id = 10415 >
    <enum>
        < name = RepositoryData code = 0 >
        < name = IMSPublicIdentity code = 10 >
        < name = IMSUserState code = 11 >
        < name = SCSCFName code = 12 >
        < name = InitialFilterCriteria code = 13 >
        < name = LocationInformation code = 14 >
        < name = UserState code = 15 >
        < name = ChargingInformation code = 16 >
        < name = MSISDN code = 17 >
        < name = PSIActivation code = 18 >
        < name = DSAI code = 19 >
        < name = ServiceLevelTraceInfo code = 21 >
        < name = IPAddressSecureBindingInformation code = 22 >
        < name = ServicePriorityLevel code = 23 >
        < name = SMSRegistrationInfo code = 24 >
        < name = UEReachabilityForIP code = 25 >
        < name = TADSinformation code = 26 >
        < name = STN_SR code = 27 >
        < name = UE_SRVCC_Capability code = 28 >
        < name = ExtendedPriority code = 29 >
        < name = CSRN code = 30 >
        < name = ReferenceLocationInformation code = 31 >
        < name = IMSI code = 32 >
        < name = IMSPrivateUserIdentity code = 33 >
        < name = IMEISV code = 34 >
        < name = UE_5G_SRVCC_Capability code = 35 >
        < name = ASRegistrationInfo code = 36 >
    </enum>
</avp>
<avp>
    <avp-name = IdentitySet type = Enumerated >
    <avp-code = 708 encrypt = no multiple = yes >
    <avp-flags = vendor null null >
    <vendor-id = 10415 >
    <enum>
        < name = ALL_IDENTITIES code = 0 >
        < name = REGISTERED_IDENTITIES code = 1 >
        < name = IMPLICIT_IDENTITIES code = 2 >
        < name = ALIAS_IDENTITIES code = 3 >
    </enum>
</avp>
<avp>
    <avp-name = RequestedDomain type = Enumerated >
    <avp-code = 706 encrypt = no multiple = no >
    <avp-flags = vendor mandatory null >
    <vendor-id = 10415 >
    <enum>
        < name = CSDomain code = 0 >
        < name = PSDomain code = 1 >
    </enum>
</avp>
<avp>
    <avp-name = CurrentLocation type = Enumerated >
    <avp-code = 707 encrypt = no multiple = no >
    <avp-flags = vendor mandatory null >
    <vendor-id = 10415 >
    <enum>
        < name = DoNotNeedInitiateActiveLocationRetrieval code = 0 >
        < name = InitiateActiveLocationRetrieval code = 1 >
    </enum>
</avp>
<avp>
    <avp-name = DSAITag type = OctetString >
    <avp-code = 711 encrypt = no multiple = yes >
    <avp-flags = vendor mandatory null >
    <vendor-id = 10415 >
</avp>
<avp>
    <avp-name = SessionPriority type = Enumerated >
    <avp-code = 650 encrypt = no multiple = no >
    <avp-flags = vendor null null >
    <vendor-id = 10415 >
    <enum>
        < name = PRIORITY_0 code = 0 >
        < name = PRIORITY_1 code = 1 >
        < name = PRIORITY_2 code = 2 >
        < name = PRIORITY_3 code = 3 >
        < name = PRIORITY_4 code = 4 >
    </enum>
</avp>
<avp>
    <avp-name = UserName type = OctetString >
    <avp-code = 1 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<avp>
    <avp-name = RequestedNodes type = Unsigned32 >
    <avp-code = 713 encrypt = no multiple = no >
    <avp-flags = vendor null null >
    <vendor-id = 10415 >
</avp>
<avp>
    <avp-name = ServingNodeIndication type = Enumerated >
    <avp-code = 714 encrypt = no multiple = no >
    <avp-flags = vendor null null >
    <vendor-id = 10415 >
    <enum>
        < name = ONLY_SERVING_NODES_REQUIRED code = 0 >
    </enum>
</avp>
<avp>
    <avp-name = PrepagingSupported type = Enumerated >
    <avp-code = 717 encrypt = no multiple = no >
    <avp-flags = vendor null null >
    <vendor-id = 10415 >
    <enum>
        < name = PREPAGING_NOT_SUPPORTED code = 0 >
        < name = PREPAGING_SUPPORTED code = 1 >
    </enum>
</avp>
<avp>
    <avp-name = LocalTimeZoneIndication type = Enumerated >
    <avp-code = 718 encrypt = no multiple = no >
    <avp-flags = vendor null null >
    <vendor-id = 10415 >
    <enum>
        < name = ONLY_LOCAL_TIME_ZONE_REQUESTED code = 0 >
        < name = LOCAL_TIME_ZONE_WITH_LOCATION_INFO_REQUESTED code = 1 >
    </enum>
</avp>
<avp>
    <avp-name = UDRFlags type = Unsigned32 >
    <avp-code = 719 encrypt = no multiple = no >
    <avp-flags = vendor null null >
    <vendor-id = 10415 >
</avp>
<grouped = CallReferenceInfo multiple = no >
    <grouped-avp-code = 720 encrypt = no >
    <grouped-avp-flags = vendor null null >
    <grouped-vendor-id = 10415 >
</grouped>
<grouped = OCSupportedFeatures multiple = no >
    <grouped-avp-code = 621 encrypt = no >
    <grouped-avp-flags = null null null >
</grouped>
<grouped = ProxyInfo multiple = yes >
    <grouped-avp-code = 284 encrypt = no >
    <grouped-avp-flags = null mandatory null >
</grouped>
<avp>
    <avp-name = RouteRecord type = OctetString >
    <avp-code = 282 encrypt = no multiple = yes >
    <avp-flags = null mandatory null >
</avp>
</message>

<message>
<command = UserDataAnswer>
<command-flags = null proxyable null null >
<cmd-code = 306 >
<protocol-version = 1 >
</command>
<avp>
    <avp-name = SessionId type = OctetString >
    <avp-code = 263 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<avp>
    <avp-name = DRMP type = Enumerated >
    <avp-code = 301 encrypt = no multiple = no >
    <avp-flags = null null null >
    <enum>
        < name = PRIORITY_0 code = 0 >
        < name = PRIORITY_1 code = 1 >
        < name = PRIORITY_2 code = 2 >
        < name = PRIORITY_3 code = 3 >
        < name = PRIORITY_4 code = 4 >
        < name = PRIORITY_5 code = 5 >
        < name = PRIORITY_6 code = 6 >
        < name = PRIORITY_7 code = 7 >
        < name = PRIORITY_8 code = 8 >
        < name = PRIORITY_9 code = 9 >
        < name = PRIORITY_10 code = 10 >
        < name = PRIORITY_11 code = 11 >
        < name = PRIORITY_12 code = 12 >
        < name = PRIORITY_13 code = 13 >
        < name = PRIORITY_14 code = 14 >
        < name = PRIORITY_15 code = 15 >
    </enum>
</avp>
<grouped = VendorSpecificApplicationId multiple = no >
    <grouped-avp-code = 260 encrypt = no >
    <grouped-avp-flags = null mandatory null >
</grouped>
<avp>
    <avp-name = ResultCode type = Unsigned32 >
    <avp-code = 268 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<grouped = ExperimentalResult multiple = no >
    <grouped-avp-code = 297 encrypt = no >
    <grouped-avp-flags = null mandatory null >
</grouped>
<avp>
    <avp-name = AuthSessionState type = Enumerated >
    <avp-code = 277 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
    <enum>
        < name = STATE_MAINTAINED code = 0 >
        < name = NO_STATE_MAINTAINED code = 1 >
    </enum>
</avp>
<avp>
    <avp-name = OriginHost type = OctetString >
    <avp-code = 264 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<avp>
    <avp-name = OriginRealm type = OctetString >
    <avp-code = 296 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<grouped = SupportedFeatures multiple = yes >
    <grouped-avp-code = 628 encrypt = no >
    <grouped-avp-flags = vendor null null >
    <grouped-vendor-id = 10415 >
</grouped>
<avp>
    <avp-name = WildcardedPublicIdentity type = OctetString >
    <avp-code = 634 encrypt = no multiple = no >
    <avp-flags = vendor null null >
    <vendor-id = 10415 >
</avp>
<avp>
    <avp-name = WildcardedIMPU type = OctetString >
    <avp-code = 636 encrypt = no multiple = no >
    <avp-flags = vendor null null >
    <vendor-id = 10415 >
</avp>
<avp>
    <avp-name = UserData type = OctetString >
    <avp-code = 702 encrypt = no multiple = no >
    <avp-flags = vendor mandatory null >
    <vendor-id = 10415 >
</avp>
<grouped = OCSupportedFeatures multiple = no >
    <grouped-avp-code = 621 encrypt = no >
    <grouped-avp-flags = null null null >
</grouped>
<grouped = OCOLR multiple = no >
    <grouped-avp-code = 623 encrypt = no >
    <grouped-avp-flags = null null null >
</grouped>
<grouped = Load multiple = yes >
    <grouped-avp-code = 650 encrypt = no >
    <grouped-avp-flags = null null null >
</grouped>
<grouped = FailedAVP multiple = no >
    <grouped-avp-code = 279 encrypt = no >
    <grouped-avp-flags = null mandatory null >
</grouped>
<grouped = ProxyInfo multiple = yes >
    <grouped-avp-code = 284 encrypt = no >
    <grouped-avp-flags = null mandatory null >
</grouped>
<avp>
    <avp-name = RouteRecord type = OctetString >
    <avp-code = 282 encrypt = no multiple = yes >
    <avp-flags = null mandatory null >
</avp>
</message>

<message>
<command = ProfileUpdateRequest>
<command-flags = request proxyable null null >
<cmd-code = 307 >
<protocol-version = 1 >
</command>
<avp>
    <avp-name = SessionId type = OctetString >
    <avp-code = 263 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<avp>
    <avp-name = DRMP type = Enumerated >
    <avp-code = 301 encrypt = no multiple = no >
    <avp-flags = null null null >
    <enum>
        < name = PRIORITY_0 code = 0 >
        < name = PRIORITY_1 code = 1 >
        < name = PRIORITY_2 code = 2 >
        < name = PRIORITY_3 code = 3 >
        < name = PRIORITY_4 code = 4 >
        < name = PRIORITY_5 code = 5 >
        < name = PRIORITY_6 code = 6 >
        < name = PRIORITY_7 code = 7 >
        < name = PRIORITY_8 code = 8 >
        < name = PRIORITY_9 code = 9 >
        < name = PRIORITY_10 code = 10 >
        < name = PRIORITY_11 code = 11 >
        < name = PRIORITY_12 code = 12 >
        < name = PRIORITY_13 code = 13 >
        < name = PRIORITY_14 code = 14 >
        < name = PRIORITY_15 code = 15 >
    </enum>
</avp>
<grouped = VendorSpecificApplicationId multiple = no >
    <grouped-avp-code = 260 encrypt = no >
    <grouped-avp-flags = null mandatory null >
</grouped>
<avp>
    <avp-name = AuthSessionState type = Enumerated >
    <avp-code = 277 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
    <enum>
        < name = STATE_MAINTAINED code = 0 >
        < name = NO_STATE_MAINTAINED code = 1 >
    </enum>
</avp>
<avp>
    <avp-name = OriginHost type = OctetString >
    <avp-code = 264 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<avp>
    <avp-name = OriginRealm type = OctetString >
    <avp-code = 296 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<avp>
    <avp-name = DestinationHost type = OctetString >
    <avp-code = 293 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<avp>
    <avp-name = DestinationRealm type = OctetString >
    <avp-code = 283 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<grouped = SupportedFeatures multiple = yes >
    <grouped-avp-code = 628 encrypt = no >
    <grouped-avp-flags = vendor null null >
    <grouped-vendor-id = 10415 >
</grouped>
<grouped = UserIdentity multiple = no >
    <grouped-avp-code = 700 encrypt = no >
    <grouped-avp-flags = vendor mandatory null >
    <grouped-vendor-id = 10415 >
</grouped>
<avp>
    <avp-name = WildcardedPublicIdentity type = OctetString >
    <avp-code = 634 encrypt = no multiple = no >
    <avp-flags = vendor null null >
    <vendor-id = 10415 >
</avp>
<avp>
    <avp-name = WildcardedIMPU type = OctetString >
    <avp-code = 636 encrypt = no multiple = no >
    <avp-flags = vendor null null >
    <vendor-id = 10415 >
</avp>
<avp>
    <avp-name = UserName type = OctetString >
    <avp-code = 1 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<avp>
    <avp-name = DataReference type = Enumerated >
    <avp-code = 703 encrypt = no multiple = yes >
    <avp-flags = vendor mandatory null >
    <vendor-id = 10415 >
    <enum>
        < name = RepositoryData code = 0 >
        < name = IMSPublicIdentity code = 10 >
        < name = IMSUserState code = 11 >
        < name = SCSCFName code = 12 >
        < name = InitialFilterCriteria code = 13 >
        < name = LocationInformation code = 14 >
        < name = UserState code = 15 >
        < name = ChargingInformation code = 16 >
        < name = MSISDN code = 17 >
        < name = PSIActivation code = 18 >
        < name = DSAI code = 19 >
        < name = ServiceLevelTraceInfo code = 21 >
        < name = IPAddressSecureBindingInformation code = 22 >
        < name = ServicePriorityLevel code = 23 >
        < name = SMSRegistrationInfo code = 24 >
        < name = UEReachabilityForIP code = 25 >
        < name = TADSinformation code = 26 >
        < name = STN_SR code = 27 >
        < name = UE_SRVCC_Capability code = 28 >
        < name = ExtendedPriority code = 29 >
        < name = CSRN code = 30 >
        < name = ReferenceLocationInformation code = 31 >
        < name = IMSI code = 32 >
        < name = IMSPrivateUserIdentity code = 33 >
        < name = IMEISV code = 34 >
        < name = UE_5G_SRVCC_Capability code = 35 >
        < name = ASRegistrationInfo code = 36 >
    </enum>
</avp>
<avp>
    <avp-name = UserData type = OctetString >
    <avp-code = 702 encrypt = no multiple = no >
    <avp-flags = vendor mandatory null >
    <vendor-id = 10415 >
</avp>
<grouped = OCSupportedFeatures multiple = no >
    <grouped-avp-code = 621 encrypt = no >
    <grouped-avp-flags = null null null >
</grouped>
<grouped = ProxyInfo multiple = yes >
    <grouped-avp-code = 284 encrypt = no >
    <grouped-avp-flags = null mandatory null >
</grouped>
<avp>
    <avp-name = RouteRecord type = OctetString >
    <avp-code = 282 encrypt = no multiple = yes >
    <avp-flags = null mandatory null >
</avp>
</message>

<message>
<command = ProfileUpdateAnswer>
<command-flags = null proxyable null null >
<cmd-code = 307 >
<protocol-version = 1 >
</command>
<avp>
    <avp-name = SessionId type = OctetString >
    <avp-code = 263 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<avp>
    <avp-name = DRMP type = Enumerated >
    <avp-code = 301 encrypt = no multiple = no >
    <avp-flags = null null null >
    <enum>
        < name = PRIORITY_0 code = 0 >
        < name = PRIORITY_1 code = 1 >
        < name = PRIORITY_2 code = 2 >
        < name = PRIORITY_3 code = 3 >
        < name = PRIORITY_4 code = 4 >
        < name = PRIORITY_5 code = 5 >
        < name = PRIORITY_6 code = 6 >
        < name = PRIORITY_7 code = 7 >
        < name = PRIORITY_8 code = 8 >
        < name = PRIORITY_9 code = 9 >
        < name = PRIORITY_10 code = 10 >
        < name = PRIORITY_11 code = 11 >
        < name = PRIORITY_12 code = 12 >
        < name = PRIORITY_13 code = 13 >
        < name = PRIORITY_14 code = 14 >
        < name = PRIORITY_15 code = 15 >
    </enum>
</avp>
<grouped = VendorSpecificApplicationId multiple = no >
    <grouped-avp-code = 260 encrypt = no >
    <grouped-avp-flags = null mandatory null >
</grouped>
<avp>
    <avp-name = ResultCode type = Unsigned32 >
    <avp-code = 268 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<grouped = ExperimentalResult multiple = no >
    <grouped-avp-code = 297 encrypt = no >
    <grouped-avp-flags = null mandatory null >
</grouped>
<avp>
    <avp-name = AuthSessionState type = Enumerated >
    <avp-code = 277 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
    <enum>
        < name = STATE_MAINTAINED code = 0 >
        < name = NO_STATE_MAINTAINED code = 1 >
    </enum>
</avp>
<avp>
    <avp-name = OriginHost type = OctetString >
    <avp-code = 264 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<avp>
    <avp-name = OriginRealm type = OctetString >
    <avp-code = 296 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<avp>
    <avp-name = WildcardedPublicIdentity type = OctetString >
    <avp-code = 634 encrypt = no multiple = no >
    <avp-flags = vendor null null >
    <vendor-id = 10415 >
</avp>
<avp>
    <avp-name = WildcardedIMPU type = OctetString >
    <avp-code = 636 encrypt = no multiple = no >
    <avp-flags = vendor null null >
    <vendor-id = 10415 >
</avp>
<grouped = RepositoryDataID multiple = no >
    <grouped-avp-code = 715 encrypt = no >
    <grouped-avp-flags = vendor null null >
    <grouped-vendor-id = 10415 >
</grouped>
<avp>
    <avp-name = DataReference type = Enumerated >
    <avp-code = 703 encrypt = no multiple = no >
    <avp-flags = vendor mandatory null >
    <vendor-id = 10415 >
    <enum>
        < name = RepositoryData code = 0 >
        < name = IMSPublicIdentity code = 10 >
        < name = IMSUserState code = 11 >
        < name = SCSCFName code = 12 >
        < name = InitialFilterCriteria code = 13 >
        < name = LocationInformation code = 14 >
        < name = UserState code = 15 >
        < name = ChargingInformation code = 16 >
        < name = MSISDN code = 17 >
        < name = PSIActivation code = 18 >
        < name = DSAI code = 19 >
        < name = ServiceLevelTraceInfo code = 21 >
        < name = IPAddressSecureBindingInformation code = 22 >
        < name = ServicePriorityLevel code = 23 >
        < name = SMSRegistrationInfo code = 24 >
        < name = UEReachabilityForIP code = 25 >
        < name = TADSinformation code = 26 >
        < name = STN_SR code = 27 >
        < name = UE_SRVCC_Capability code = 28 >
        < name = ExtendedPriority code = 29 >
        < name = CSRN code = 30 >
        < name = ReferenceLocationInformation code = 31 >
        < name = IMSI code = 32 >
        < name = IMSPrivateUserIdentity code = 33 >
        < name = IMEISV code = 34 >
        < name = UE_5G_SRVCC_Capability code = 35 >
        < name = ASRegistrationInfo code = 36 >
    </enum>
</avp>
<grouped = SupportedFeatures multiple = yes >
    <grouped-avp-code = 628 encrypt = no >
    <grouped-avp-flags = vendor null null >
    <grouped-vendor-id = 10415 >
</grouped>
<grouped = OCSupportedFeatures multiple = no >
    <grouped-avp-code = 621 encrypt = no >
    <grouped-avp-flags = null null null >
</grouped>
<grouped = OCOLR multiple = no >
    <grouped-avp-code = 623 encrypt = no >
    <grouped-avp-flags = null null null >
</grouped>
<grouped = Load multiple = yes >
    <grouped-avp-code = 650 encrypt = no >
    <grouped-avp-flags = null null null >
</grouped>
<grouped = FailedAVP multiple = no >
    <grouped-avp-code = 279 encrypt = no >
    <grouped-avp-flags = null mandatory null >
</grouped>
<grouped = ProxyInfo multiple = yes >
    <grouped-avp-code = 284 encrypt = no >
    <grouped-avp-flags = null mandatory null >
</grouped>
<avp>
    <avp-name = RouteRecord type = OctetString >
    <avp-code = 282 encrypt = no multiple = yes >
    <avp-flags = null mandatory null >
</avp>
</message>

<message>
<command = SubscribeNotificationsRequest>
<command-flags = request proxyable null null >
<cmd-code = 308 >
<protocol-version = 1 >
</command>
<avp>
    <avp-name = SessionId type = OctetString >
    <avp-code = 263 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<avp>
    <avp-name = DRMP type = Enumerated >
    <avp-code = 301 encrypt = no multiple = no >
    <avp-flags = null null null >
    <enum>
        < name = PRIORITY_0 code = 0 >
        < name = PRIORITY_1 code = 1 >
        < name = PRIORITY_2 code = 2 >
        < name = PRIORITY_3 code = 3 >
        < name = PRIORITY_4 code = 4 >
        < name = PRIORITY_5 code = 5 >
        < name = PRIORITY_6 code = 6 >
        < name = PRIORITY_7 code = 7 >
        < name = PRIORITY_8 code = 8 >
        < name = PRIORITY_9 code = 9 >
        < name = PRIORITY_10 code = 10 >
        < name = PRIORITY_11 code = 11 >
        < name = PRIORITY_12 code = 12 >
        < name = PRIORITY_13 code = 13 >
        < name = PRIORITY_14 code = 14 >
        < name = PRIORITY_15 code = 15 >
    </enum>
</avp>
<grouped = VendorSpecificApplicationId multiple = no >
    <grouped-avp-code = 260 encrypt = no >
    <grouped-avp-flags = null mandatory null >
</grouped>
<avp>
    <avp-name = AuthSessionState type = Enumerated >
    <avp-code = 277 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
    <enum>
        < name = STATE_MAINTAINED code = 0 >
        < name = NO_STATE_MAINTAINED code = 1 >
    </enum>
</avp>
<avp>
    <avp-name = OriginHost type = OctetString >
    <avp-code = 264 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<avp>
    <avp-name = OriginRealm type = OctetString >
    <avp-code = 296 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<avp>
    <avp-name = DestinationHost type = OctetString >
    <avp-code = 293 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<avp>
    <avp-name = DestinationRealm type = OctetString >
    <avp-code = 283 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<grouped = SupportedFeatures multiple = yes >
    <grouped-avp-code = 628 encrypt = no >
    <grouped-avp-flags = vendor null null >
    <grouped-vendor-id = 10415 >
</grouped>
<grouped = UserIdentity multiple = no >
    <grouped-avp-code = 700 encrypt = no >
    <grouped-avp-flags = vendor mandatory null >
    <grouped-vendor-id = 10415 >
</grouped>
<avp>
    <avp-name = WildcardedPublicIdentity type = OctetString >
    <avp-code = 634 encrypt = no multiple = no >
    <avp-flags = vendor null null >
    <vendor-id = 10415 >
</avp>
<avp>
    <avp-name = WildcardedIMPU type = OctetString >
    <avp-code = 636 encrypt = no multiple = no >
    <avp-flags = vendor null null >
    <vendor-id = 10415 >
</avp>
<avp>
    <avp-name = ServiceIndication type = OctetString >
    <avp-code = 704 encrypt = no multiple = yes >
    <avp-flags = vendor mandatory null >
    <vendor-id = 10415 >
</avp>
<avp>
    <avp-name = SendDataIndication type = Enumerated >
    <avp-code = 710 encrypt = no multiple = no >
    <avp-flags = vendor null null >
    <vendor-id = 10415 >
    <enum>
        < name = USER_DATA_NOT_REQUESTED code = 0 >
        < name = USER_DATA_REQUESTED code = 1 >
    </enum>
</avp>
<avp>
    <avp-name = ServerName type = OctetString >
    <avp-code = 602 encrypt = no multiple = no >
    <avp-flags = vendor mandatory null >
    <vendor-id = 10415 >
</avp>
<avp>
    <avp-name = SubsReqType type = Enumerated >
    <avp-code = 705 encrypt = no multiple = no >
    <avp-flags = vendor mandatory null >
    <vendor-id = 10415 >
    <enum>
        < name = Subscribe code = 0 >
        < name = Unsubscribe code = 1 >
    </enum>
</avp>
<avp>
    <avp-name = DataReference type = Enumerated >
    <avp-code = 703 encrypt = no multiple = yes >
    <avp-flags = vendor mandatory null >
    <vendor-id = 10415 >
    <enum>
        < name = RepositoryData code = 0 >
        < name = IMSPublicIdentity code = 10 >
        < name = IMSUserState code = 11 >
        < name = SCSCFName code = 12 >
        < name = InitialFilterCriteria code = 13 >
        < name = LocationInformation code = 14 >
        < name = UserState code = 15 >
        < name = ChargingInformation code = 16 >
        < name = MSISDN code = 17 >
        < name = PSIActivation code = 18 >
        < name = DSAI code = 19 >
        < name = ServiceLevelTraceInfo code = 21 >
        < name = IPAddressSecureBindingInformation code = 22 >
        < name = ServicePriorityLevel code = 23 >
        < name = SMSRegistrationInfo code = 24 >
        < name = UEReachabilityForIP code = 25 >
        < name = TADSinformation code = 26 >
        < name = STN_SR code = 27 >
        < name = UE_SRVCC_Capability code = 28 >
        < name = ExtendedPriority code = 29 >
        < name = CSRN code = 30 >
        < name = ReferenceLocationInformation code = 31 >
        < name = IMSI code = 32 >
        < name = IMSPrivateUserIdentity code = 33 >
        < name = IMEISV code = 34 >
        < name = UE_5G_SRVCC_Capability code = 35 >
        < name = ASRegistrationInfo code = 36 >
    </enum>
</avp>
<avp>
    <avp-name = IdentitySet type = Enumerated >
    <avp-code = 708 encrypt = no multiple = yes >
    <avp-flags = vendor null null >
    <vendor-id = 10415 >
    <enum>
        < name = ALL_IDENTITIES code = 0 >
        < name = REGISTERED_IDENTITIES code = 1 >
        < name = IMPLICIT_IDENTITIES code = 2 >
        < name = ALIAS_IDENTITIES code = 3 >
    </enum>
</avp>
<avp>
    <avp-name = ExpiryTime type = Time >
    <avp-code = 709 encrypt = no multiple = no >
    <avp-flags = vendor null null >
    <vendor-id = 10415 >
</avp>
<avp>
    <avp-name = DSAITag type = OctetString >
    <avp-code = 711 encrypt = no multiple = yes >
    <avp-flags = vendor mandatory null >
    <vendor-id = 10415 >
</avp>
<avp>
    <avp-name = OneTimeNotification type = Enumerated >
    <avp-code = 712 encrypt = no multiple = no >
    <avp-flags = vendor null null >
    <vendor-id = 10415 >
    <enum>
        < name = ONE_TIME_NOTIFICATION_REQUESTED code = 0 >
    </enum>
</avp>
<avp>
    <avp-name = UserName type = OctetString >
    <avp-code = 1 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<grouped = OCSupportedFeatures multiple = no >
    <grouped-avp-code = 621 encrypt = no >
    <grouped-avp-flags = null null null >
</grouped>
<grouped = ProxyInfo multiple = yes >
    <grouped-avp-code = 284 encrypt = no >
    <grouped-avp-flags = null mandatory null >
</grouped>
<avp>
    <avp-name = RouteRecord type = OctetString >
    <avp-code = 282 encrypt = no multiple = yes >
    <avp-flags = null mandatory null >
</avp>
</message>

<message>
<command = SubscribeNotificationsAnswer>
<command-flags = null proxyable null null >
<cmd-code = 308 >
<protocol-version = 1 >
</command>
<avp>
    <avp-name = SessionId type = OctetString >
    <avp-code = 263 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<avp>
    <avp-name = DRMP type = Enumerated >
    <avp-code = 301 encrypt = no multiple = no >
    <avp-flags = null null null >
    <enum>
        < name = PRIORITY_0 code = 0 >
        < name = PRIORITY_1 code = 1 >
        < name = PRIORITY_2 code = 2 >
        < name = PRIORITY_3 code = 3 >
        < name = PRIORITY_4 code = 4 >
        < name = PRIORITY_5 code = 5 >
        < name = PRIORITY_6 code = 6 >
        < name = PRIORITY_7 code = 7 >
        < name = PRIORITY_8 code = 8 >
        < name = PRIORITY_9 code = 9 >
        < name = PRIORITY_10 code = 10 >
        < name = PRIORITY_11 code = 11 >
        < name = PRIORITY_12 code = 12 >
        < name = PRIORITY_13 code = 13 >
        < name = PRIORITY_14 code = 14 >
        < name = PRIORITY_15 code = 15 >
    </enum>
</avp>
<grouped = VendorSpecificApplicationId multiple = no >
    <grouped-avp-code = 260 encrypt = no >
    <grouped-avp-flags = null mandatory null >
</grouped>
<avp>
    <avp-name = AuthSessionState type = Enumerated >
    <avp-code = 277 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
    <enum>
        < name = STATE_MAINTAINED code = 0 >
        < name = NO_STATE_MAINTAINED code = 1 >
    </enum>
</avp>
<avp>
    <avp-name = ResultCode type = Unsigned32 >
    <avp-code = 268 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<grouped = ExperimentalResult multiple = no >
    <grouped-avp-code = 297 encrypt = no >
    <grouped-avp-flags = null mandatory null >
</grouped>
<avp>
    <avp-name = OriginHost type = OctetString >
    <avp-code = 264 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<avp>
    <avp-name = OriginRealm type = OctetString >
    <avp-code = 296 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<avp>
    <avp-name = WildcardedPublicIdentity type = OctetString >
    <avp-code = 634 encrypt = no multiple = no >
    <avp-flags = vendor null null >
    <vendor-id = 10415 >
</avp>
<avp>
    <avp-name = WildcardedIMPU type = OctetString >
    <avp-code = 636 encrypt = no multiple = no >
    <avp-flags = vendor null null >
    <vendor-id = 10415 >
</avp>
<grouped = SupportedFeatures multiple = yes >
    <grouped-avp-code = 628 encrypt = no >
    <grouped-avp-flags = vendor null null >
    <grouped-vendor-id = 10415 >
</grouped>
<avp>
    <avp-name = UserData type = OctetString >
    <avp-code = 702 encrypt = no multiple = no >
    <avp-flags = vendor mandatory null >
    <vendor-id = 10415 >
</avp>
<avp>
    <avp-name = ExpiryTime type = Time >
    <avp-code = 709 encrypt = no multiple = no >
    <avp-flags = vendor null null >
    <vendor-id = 10415 >
</avp>
<grouped = OCSupportedFeatures multiple = no >
    <grouped-avp-code = 621 encrypt = no >
    <grouped-avp-flags = null null null >
</grouped>
<grouped = OCOLR multiple = no >
    <grouped-avp-code = 623 encrypt = no >
    <grouped-avp-flags = null null null >
</grouped>
<grouped = Load multiple = yes >
    <grouped-avp-code = 650 encrypt = no >
    <grouped-avp-flags = null null null >
</grouped>
<grouped = FailedAVP multiple = no >
    <grouped-avp-code = 279 encrypt = no >
    <grouped-avp-flags = null mandatory null >
</grouped>
<grouped = ProxyInfo multiple = yes >
    <grouped-avp-code = 284 encrypt = no >
    <grouped-avp-flags = null mandatory null >
</grouped>
<avp>
    <avp-name = RouteRecord type = OctetString >
    <avp-code = 282 encrypt = no multiple = yes >
    <avp-flags = null mandatory null >
</avp>
</message>

<message>
<command = PushNotificationRequest>
<command-flags = request proxyable null null >
<cmd-code = 309 >
<protocol-version = 1 >
</command>
<avp>
    <avp-name = SessionId type = OctetString >
    <avp-code = 263 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<avp>
    <avp-name = DRMP type = Enumerated >
    <avp-code = 301 encrypt = no multiple = no >
    <avp-flags = null null null >
    <enum>
        < name = PRIORITY_0 code = 0 >
        < name = PRIORITY_1 code = 1 >
        < name = PRIORITY_2 code = 2 >
        < name = PRIORITY_3 code = 3 >
        < name = PRIORITY_4 code = 4 >
        < name = PRIORITY_5 code = 5 >
        < name = PRIORITY_6 code = 6 >
        < name = PRIORITY_7 code = 7 >
        < name = PRIORITY_8 code = 8 >
        < name = PRIORITY_9 code = 9 >
        < name = PRIORITY_10 code = 10 >
        < name = PRIORITY_11 code = 11 >
        < name = PRIORITY_12 code = 12 >
        < name = PRIORITY_13 code = 13 >
        < name = PRIORITY_14 code = 14 >
        < name = PRIORITY_15 code = 15 >
    </enum>
</avp>
<grouped = VendorSpecificApplicationId multiple = no >
    <grouped-avp-code = 260 encrypt = no >
    <grouped-avp-flags = null mandatory null >
</grouped>
<avp>
    <avp-name = AuthSessionState type = Enumerated >
    <avp-code = 277 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
    <enum>
        < name = STATE_MAINTAINED code = 0 >
        < name = NO_STATE_MAINTAINED code = 1 >
    </enum>
</avp>
<avp>
    <avp-name = OriginHost type = OctetString >
    <avp-code = 264 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<avp>
    <avp-name = OriginRealm type = OctetString >
    <avp-code = 296 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<avp>
    <avp-name = DestinationHost type = OctetString >
    <avp-code = 293 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<avp>
    <avp-name = DestinationRealm type = OctetString >
    <avp-code = 283 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<grouped = SupportedFeatures multiple = yes >
    <grouped-avp-code = 628 encrypt = no >
    <grouped-avp-flags = vendor null null >
    <grouped-vendor-id = 10415 >
</grouped>
<grouped = UserIdentity multiple = no >
    <grouped-avp-code = 700 encrypt = no >
    <grouped-avp-flags = vendor mandatory null >
    <grouped-vendor-id = 10415 >
</grouped>
<avp>
    <avp-name = WildcardedPublicIdentity type = OctetString >
    <avp-code = 634 encrypt = no multiple = no >
    <avp-flags = vendor null null >
    <vendor-id = 10415 >
</avp>
<avp>
    <avp-name = WildcardedIMPU type = OctetString >
    <avp-code = 636 encrypt = no multiple = no >
    <avp-flags = vendor null null >
    <vendor-id = 10415 >
</avp>
<avp>
    <avp-name = UserName type = OctetString >
    <avp-code = 1 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<avp>
    <avp-name = UserData type = OctetString >
    <avp-code = 702 encrypt = no multiple = no >
    <avp-flags = vendor mandatory null >
    <vendor-id = 10415 >
</avp>
<grouped = ProxyInfo multiple = yes >
    <grouped-avp-code = 284 encrypt = no >
    <grouped-avp-flags = null mandatory null >
</grouped>
<avp>
    <avp-name = RouteRecord type = OctetString >
    <avp-code = 282 encrypt = no multiple = yes >
    <avp-flags = null mandatory null >
</avp>
</message>

<message>
<command = PushNotificationAnswer>
<command-flags = null proxyable null null >
<cmd-code = 309 >
<protocol-version = 1 >
</command>
<avp>
    <avp-name = SessionId type = OctetString >
    <avp-code = 263 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<avp>
    <avp-name = DRMP type = Enumerated >
    <avp-code = 301 encrypt = no multiple = no >
    <avp-flags = null null null >
    <enum>
        < name = PRIORITY_0 code = 0 >
        < name = PRIORITY_1 code = 1 >
        < name = PRIORITY_2 code = 2 >
        < name = PRIORITY_3 code = 3 >
        < name = PRIORITY_4 code = 4 >
        < name = PRIORITY_5 code = 5 >
        < name = PRIORITY_6 code = 6 >
        < name = PRIORITY_7 code = 7 >
        < name = PRIORITY_8 code = 8 >
        < name = PRIORITY_9 code = 9 >
        < name = PRIORITY_10 code = 10 >
        < name = PRIORITY_11 code = 11 >
        < name = PRIORITY_12 code = 12 >
        < name = PRIORITY_13 code = 13 >
        < name = PRIORITY_14 code = 14 >
        < name = PRIORITY_15 code = 15 >
    </enum>
</avp>
<grouped = VendorSpecificApplicationId multiple = no >
    <grouped-avp-code = 260 encrypt = no >
    <grouped-avp-flags = null mandatory null >
</grouped>
<avp>
    <avp-name = ResultCode type = Unsigned32 >
    <avp-code = 268 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<grouped = ExperimentalResult multiple = no >
    <grouped-avp-code = 297 encrypt = no >
    <grouped-avp-flags = null mandatory null >
</grouped>
<avp>
    <avp-name = AuthSessionState type = Enumerated >
    <avp-code = 277 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
    <enum>
        < name = STATE_MAINTAINED code = 0 >
        < name = NO_STATE_MAINTAINED code = 1 >
    </enum>
</avp>
<avp>
    <avp-name = OriginHost type = OctetString >
    <avp-code = 264 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<avp>
    <avp-name = OriginRealm type = OctetString >
    <avp-code = 296 encrypt = no multiple = no >
    <avp-flags = null mandatory null >
</avp>
<grouped = SupportedFeatures multiple = yes >
    <grouped-avp-code = 628 encrypt = no >
    <grouped-avp-flags = vendor null null >
    <grouped-vendor-id = 10415 >
</grouped>
<grouped = FailedAVP multiple = no >
    <grouped-avp-code = 279 encrypt = no >
    <grouped-avp-flags = null mandatory null >
</grouped>
<grouped = ProxyInfo multiple = yes >
    <grouped-avp-code = 284 encrypt = no >
    <grouped-avp-flags = null mandatory null >
</grouped>
<avp>
    <avp-name = RouteRecord type = OctetString >
    <avp-code = 282 encrypt = no multiple = yes >
    <avp-flags = null mandatory null >
</avp>
</message>

<grouped-avp>
    <grouped-avp-name = VendorSpecificApplicationId type = Grouped >
    <grouped-avp-code = 260 encrypt = no >
    <grouped-avp-flags = null mandatory null >
    <avp>
        <avp-name = VendorId type = Unsigned32 >
        <avp-code = 266 encrypt = no multiple = no >
        <avp-flags = null mandatory null >
    </avp>
    <avp>
        <avp-name = AuthApplicationId type = Unsigned32 >
        <avp-code = 258 encrypt = no multiple = no >
        <avp-flags = null mandatory null >
    </avp>
    <avp>
        <avp-name = AcctApplicationId type = Unsigned32 >
        <avp-code = 259 encrypt = no multiple = no >
        <avp-flags = null null null >
    </avp>
</grouped-avp>

<grouped-avp>
    <grouped-avp-name = ExperimentalResult type = Grouped >
    <grouped-avp-code = 297 encrypt = no >
    <grouped-avp-flags = null mandatory null >
    <avp>
        <avp-name = VendorId type = Unsigned32 >
        <avp-code = 266 encrypt = no multiple = no >
        <avp-flags = null mandatory null >
    </avp>
    <avp>
        <avp-name = ExperimentalResultCode type = Unsigned32 >
        <avp-code = 298 encrypt = no multiple = no >
        <avp-flags = null mandatory null >
    </avp>
</grouped-avp>

<grouped-avp>
    <grouped-avp-name = FailedAVP type = Grouped >
    <grouped-avp-code = 279 encrypt = no >
    <grouped-avp-flags = null mandatory null >
</grouped-avp>

<grouped-avp>
    <grouped-avp-name = ProxyInfo type = Grouped >
    <grouped-avp-code = 284 encrypt = no >
    <grouped-avp-flags = null mandatory null >
    <avp>
        <avp-name = ProxyHost type = OctetString >
        <avp-code = 280 encrypt = no multiple = no >
        <avp-flags = null mandatory null >
    </avp>
    <avp>
        <avp-name = ProxyState type = OctetString >
        <avp-code = 33 encrypt = no multiple = no >
        <avp-flags = null mandatory null >
    </avp>
</grouped-avp>

<grouped-avp>
    <grouped-avp-name = SupportedFeatures type = Grouped >
    <grouped-avp-code = 628 encrypt = no >
    <grouped-avp-flags = vendor null null >
    <grouped-vendor-id = 10415 >
    <avp>
        <avp-name = VendorId type = Unsigned32 >
        <avp-code = 266 encrypt = no multiple = no >
        <avp-flags = null mandatory null >
    </avp>
    <avp>
        <avp-name = FeatureListID type = Unsigned32 >
        <avp-code = 629 encrypt = no multiple = no >
        <avp-flags = vendor null null >
        <vendor-id = 10415 >
    </avp>
    <avp>
        <avp-name = FeatureList type = Unsigned32 >
        <avp-code = 630 encrypt = no multiple = no >
        <avp-flags = vendor null null >
        <vendor-id = 10415 >
    </avp>
</grouped-avp>

<grouped-avp>
    <grouped-avp-name = SupportedApplications type = Grouped >
    <grouped-avp-code = 631 encrypt = no >
    <grouped-avp-flags = vendor null null >
    <grouped-vendor-id = 10415 >
    <avp>
        <avp-name = AuthApplicationId type = Unsigned32 >
        <avp-code = 258 encrypt = no multiple = yes >
        <avp-flags = null mandatory null >
    </avp>
    <avp>
        <avp-name = AcctApplicationId type = Unsigned32 >
        <avp-code = 259 encrypt = no multiple = yes >
        <avp-flags = null null null >
    </avp>
    <grouped = VendorSpecificApplicationId multiple = yes >
        <grouped-avp-code = 260 encrypt = no >
        <grouped-avp-flags = null mandatory null >
    </grouped>
</grouped-avp>

<grouped-avp>
    <grouped-avp-name = OCSupportedFeatures type = Grouped >
    <grouped-avp-code = 621 encrypt = no >
    <grouped-avp-flags = null null null >
    <avp>
        <avp-name = OCFeatureVector type = Unsigned64 >
        <avp-code = 622 encrypt = no multiple = no >
        <avp-flags = null null null >
    </avp>
</grouped-avp>

<grouped-avp>
    <grouped-avp-name = OCOLR type = Grouped >
    <grouped-avp-code = 623 encrypt = no >
    <grouped-avp-flags = null null null >
    <avp>
        <avp-name = OCSequenceNumber type = Unsigned64 >
        <avp-code = 624 encrypt = no multiple = no >
        <avp-flags = null null null >
    </avp>
    <avp>
        <avp-name = OCReportType type = Enumerated >
        <avp-code = 626 encrypt = no multiple = no >
        <avp-flags = null null null >
        <enum>
            < name = HOST_REPORT code = 0 >
            < name = REALM_REPORT code = 1 >
        </enum>
    </avp>
    <avp>
        <avp-name = OCReductionPercentage type = Unsigned32 >
        <avp-code = 627 encrypt = no multiple = no >
        <avp-flags = null null null >
    </avp>
    <avp>
        <avp-name = OCValidityDuration type = Unsigned32 >
        <avp-code = 625 encrypt = no multiple = no >
        <avp-flags = null null null >
    </avp>
</grouped-avp>

<grouped-avp>
    <grouped-avp-name = Load type = Grouped >
    <grouped-avp-code = 650 encrypt = no >
    <grouped-avp-flags = null null null >
    <avp>
        <avp-name = LoadType type = Enumerated >
        <avp-code = 651 encrypt = no multiple = no >
        <avp-flags = null null null >
        <enum>
            < name = HOST code = 0 >
            < name = PEER code = 1 >
        </enum>
    </avp>
    <avp>
        <avp-name = LoadValue type = Unsigned64 >
        <avp-code = 652 encrypt = no multiple = no >
        <avp-flags = null null null >
    </avp>
    <avp>
        <avp-name = SourceID type = OctetString >
        <avp-code = 649 encrypt = no multiple = no >
        <avp-flags = null null null >
    </avp>
</grouped-avp>

<grouped-avp>
    <grouped-avp-name = UserIdentity type = Grouped >
    <grouped-avp-code = 700 encrypt = no >
    <grouped-avp-flags = vendor mandatory null >
    <grouped-vendor-id = 10415 >
    <avp>
        <avp-name = PublicIdentity type = OctetString >
        <avp-code = 601 encrypt = no multiple = no >
        <avp-flags = vendor mandatory null >
        <vendor-id = 10415 >
    </avp>
    <avp>
        <avp-name = MSISDN type = OctetString >
        <avp-code = 701 encrypt = no multiple = no >
        <avp-flags = vendor mandatory null >
        <vendor-id = 10415 >
    </avp>
    <avp>
        <avp-name = ExternalIdentifier type = OctetString >
        <avp-code = 3111 encrypt = no multiple = no >
        <avp-flags = vendor mandatory null >
        <vendor-id = 10415 >
    </avp>
</grouped-avp>

<grouped-avp>
    <grouped-avp-name = RepositoryDataID type = Grouped >
    <grouped-avp-code = 715 encrypt = no >
    <grouped-avp-flags = vendor null null >
    <grouped-vendor-id = 10415 >
    <avp>
        <avp-name = ServiceIndication type = OctetString >
        <avp-code = 704 encrypt = no multiple = no >
        <avp-flags = vendor mandatory null >
        <vendor-id = 10415 >
    </avp>
    <avp>
        <avp-name = SequenceNumber type = Unsigned32 >
        <avp-code = 716 encrypt = no multiple = no >
        <avp-flags = vendor null null >
        <vendor-id = 10415 >
    </avp>
</grouped-avp>

<grouped-avp>
    <grouped-avp-name = CallReferenceInfo type = Grouped >
    <grouped-avp-code = 720 encrypt = no >
    <grouped-avp-flags = vendor null null >
    <grouped-vendor-id = 10415 >
    <avp>
        <avp-name = CallReferenceNumber type = OctetString >
        <avp-code = 721 encrypt = no multiple = no >
        <avp-flags = vendor null null >
        <vendor-id = 10415 >
    </avp>
    <avp>
        <avp-name = ASNumber type = OctetString >
        <avp-code = 722 encrypt = no multiple = no >
        <avp-flags = vendor null null >
        <vendor-id = 10415 >
    </avp>
</grouped-avp>
