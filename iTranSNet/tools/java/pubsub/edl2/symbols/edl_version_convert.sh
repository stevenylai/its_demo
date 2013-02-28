cat ${1}|sed 's/package pubsub.edl2.frontend/package pubsub.edl2.symbols/g' >tmp.java
mv tmp.java ${1}
