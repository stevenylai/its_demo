cat ${1}|sed 's/edl/edl2/g' >tmp.java
mv tmp.java ${1}
