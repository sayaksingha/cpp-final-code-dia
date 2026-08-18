import re

with open('c:/Tayana_Project/Dra/Codebase/dra-diameter-sh-cx-sd/diameter-dictionary_060726_sd-cx-sh/dictionary/dont_touch_it', 'r') as f:
    text = f.read()

grouped_avps = text.split("-- =====================================================================")[-1]

# Extract all individual AVP blocks
avp_blocks = re.findall(r'(<avp>.*?</avp>)', text, re.DOTALL | re.IGNORECASE)
grouped_blocks = re.findall(r'(<grouped\s*=\s*\w+.*?</grouped>)', text, re.DOTALL | re.IGNORECASE)

avp_dict = {}
for block in avp_blocks:
    m = re.search(r'<avp-name\s*=\s*(\w+)\s+', block, re.IGNORECASE)
    if m:
        name = m.group(1)
        # only keep the first one
        if name not in avp_dict:
            avp_dict[name] = block

for block in grouped_blocks:
    m = re.search(r'<grouped\s*=\s*(\w+)\s+', block, re.IGNORECASE)
    if m:
        name = m.group(1)
        if name not in avp_dict:
            avp_dict[name] = block

def get_avp_def(name):
    if name in avp_dict:
        return avp_dict[name]
    
    # Check if we need to mock it if not in dont_touch_it
    if name == "VendorSpecificApplicationId":
        return """<grouped = VendorSpecificApplicationId multiple = yes >
    <grouped-avp-code = 260 encrypt = yes >
    <grouped-avp-flags = null mandatory null >
    <grouped-vendor-id = 10415 >
</grouped>"""
    return f"<!-- MISSING DEFINITION FOR {name} -->"

messages = []

def build_message(command, cmd_code, flags, avp_list):
    res = f"<message>\n\n    <command = {command}>\n        <cmd-code = {cmd_code} >\n        <command-flags = {flags} >\n        <protocol-version = 1 >\n    </command>\n\n"
    for avp in avp_list:
        avp_def = get_avp_def(avp)
        res += "    " + avp_def.replace('\n', '\n    ') + "\n"
    res += "</message>\n"
    return res

# 1. TSR
tsr_avps = ["SessionId", "VendorSpecificApplicationId", "OriginHost", "OriginRealm", "DestinationRealm", "DestinationHost", "OriginStateId", "SupportedFeatures", "FramedIPAddress", "FramedIPv6Prefix", "IPCANType", "RATType", "CalledStationId", "ADCRuleInstall", "EventTrigger", "ProxyInfo", "RouteRecord"]

# 2. TSA
tsa_avps = ["SessionId", "VendorSpecificApplicationId", "OriginHost", "OriginRealm", "ResultCode", "ExperimentalResult", "OriginStateId", "SupportedFeatures", "ADCRuleReport", "EventReportIndication", "ErrorMessage", "ErrorReportingHost", "FailedAVP", "ProxyInfo", "RouteRecord"]

# 3. CCR
ccr_avps = ["SessionId", "AuthApplicationId", "OriginHost", "OriginRealm", "DestinationRealm", "DestinationHost", "CCRequestType", "CCRequestNumber", "OriginStateId", "FramedIPAddress", "FramedIPv6Prefix", "ADCRuleReport", "ApplicationDetectionInformation", "EventTrigger", "EventReportIndication", "ProxyInfo", "RouteRecord", "SupportedFeatures"]

# 4. CCA
cca_avps = ["SessionId", "AuthApplicationId", "OriginHost", "OriginRealm", "ResultCode", "ExperimentalResult", "CCRequestType", "CCRequestNumber", "FramedIPv6Prefix", "EventTrigger", "EventReportIndication", "OriginStateId", "RedirectHost", "RedirectHostUsage", "RedirectMaxCacheTime", "ADCRuleRemove", "ADCRuleInstall", "ErrorMessage", "ErrorReportingHost", "FailedAVP", "ProxyInfo", "RouteRecord", "SupportedFeatures"]

# 5. RAR
rar_avps = ["SessionId", "AuthApplicationId", "OriginHost", "OriginRealm", "DestinationRealm", "DestinationHost", "ReAuthRequestType", "SessionReleaseCause", "OriginStateId", "EventTrigger", "EventReportIndication", "ADCRuleRemove", "ADCRuleInstall", "ProxyInfo", "RouteRecord"]

# 6. RAA
raa_avps = ["SessionId", "OriginHost", "OriginRealm", "ResultCode", "ExperimentalResult", "OriginStateId", "ADCRuleReport", "EventReportIndication", "ErrorMessage", "ErrorReportingHost", "FailedAVP", "ProxyInfo"]

with open("diameter.dictionary.sd.new2", "w") as f:
    f.write("-- diameter.dictionary.sd\n")
    f.write("-- Sd reference point (PCRF <-> TDF), 3GPP TS 29.212. Application-Id = 16777303\n")
    f.write("-- Vendor-Id = 10415 (3GPP)\n\n")
    
    f.write("-- =====================================================================\n")
    f.write("-- 1. TDF-Session-Request (TSR) - PCRF -> TDF\n")
    f.write("-- =====================================================================\n")
    f.write(build_message("TDFSessionRequest", 8388637, "request proxyable error transmit", tsr_avps))
    
    f.write("\n-- =====================================================================\n")
    f.write("-- 2. TDF-Session-Answer (TSA) - TDF -> PCRF\n")
    f.write("-- =====================================================================\n")
    f.write(build_message("TDFSessionAnswer", 8388637, "null proxyable null null", tsa_avps))
    
    f.write("\n-- =====================================================================\n")
    f.write("-- 3. CC-Request Sd (CCR) - TDF -> PCRF\n")
    f.write("-- =====================================================================\n")
    f.write(build_message("CreditControlRequestSd", 272, "request proxyable error transmit", ccr_avps))
    
    f.write("\n-- =====================================================================\n")
    f.write("-- 4. CC-Answer Sd (CCA) - PCRF -> TDF\n")
    f.write("-- =====================================================================\n")
    f.write(build_message("CreditControlAnswerSd", 272, "null proxyable null null", cca_avps))
    
    f.write("\n-- =====================================================================\n")
    f.write("-- 5. Re-Auth-Request Sd (RAR) - PCRF -> TDF\n")
    f.write("-- =====================================================================\n")
    f.write(build_message("ReAuthRequestSd", 258, "request proxyable error transmit", rar_avps))
    
    f.write("\n-- =====================================================================\n")
    f.write("-- 6. Re-Auth-Answer Sd (RAA) - TDF -> PCRF\n")
    f.write("-- =====================================================================\n")
    f.write(build_message("ReAuthAnswerSd", 258, "null proxyable null null", raa_avps))

    f.write("\n-- =====================================================================\n")
    f.write(grouped_avps)

print("Created diameter.dictionary.sd.new2")
