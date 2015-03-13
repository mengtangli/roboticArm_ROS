
(cl:in-package :asdf)

(defsystem "ros_tut-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "num" :depends-on ("_package_num"))
    (:file "_package_num" :depends-on ("_package"))
    (:file "servo" :depends-on ("_package_servo"))
    (:file "_package_servo" :depends-on ("_package"))
  ))