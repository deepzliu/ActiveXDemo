:: IMPORTANT - Must copy ActiveX OCX file to same directory as INF and CAB files
copy .\release\myactivex.ocx .
cabarc -s 6144 N myactivex.cab ./myactivex.ocx ./myactivex.inf
