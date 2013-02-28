cat ${1}|sed 's/import pubsub.edl2.frontend.\*;//g' >tmp.java
mv tmp.java ${1}
