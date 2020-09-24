Option Explicit

'******************************************************************************************************************************
'********** Configuration                                                                                            **********
'******************************************************************************************************************************

'
'   COM authentication
'
'Private Const ADMIN  = "Administrator"
'Private Const PASSWD = "#SUPERSECRET"

'******************************************************************************************************************************
'********** hMailServer Triggers                                                                                     **********
'******************************************************************************************************************************

'Sub OnClientConnect(oClient)
'End Sub

'Sub OnHELO(oClient)
'End Sub

'Sub OnClientLogon(oClient, sPassword)
'End Sub

'*
'*  ********** SPAM test: DNSBlackLists, HeloHost, MXRecords, SPF
'*

'Sub OnSMTPData(oClient, oMessage)
'End Sub

'*
'*  ********** SPAM test: URIBL, DKIM, SpamAssassin, Saving EML to DATA
'*

'Sub OnAcceptMessage(oClient, oMessage)
'End Sub

'Sub OnDeliveryStart(oMessage)
'End Sub

'*
'*  ********** Antivirus check, Global rules
'*

'Sub OnDeliverMessage(oMessage)
'End Sub

'*
'*  ********** Local rules, Message delivered to recipient(s)
'*

'Sub OnDeliveryFailed(oMessage, sRecipient, sErrorMessage)
'End Sub

'Sub OnError(iSeverity, iCode, sSource, sDescription)
'End Sub

'Sub OnBackupCompleted()
'End Sub

'Sub OnBackupFailed(sReason)
'End Sub

'Sub OnExternalAccountDownload(oFetchAccount, oMessage, sRemoteUID)
'End Sub

'******************************************************************************************************************************
'********** END                                                                                                      **********
'******************************************************************************************************************************
