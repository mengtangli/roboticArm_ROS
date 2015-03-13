
(cl:in-package :asdf)

(defsystem "brazo_fer-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ReadServos" :depends-on ("_package_ReadServos"))
    (:file "_package_ReadServos" :depends-on ("_package"))
    (:file "WriteServos" :depends-on ("_package_WriteServos"))
    (:file "_package_WriteServos" :depends-on ("_package"))
    (:file "Servos" :depends-on ("_package_Servos"))
    (:file "_package_Servos" :depends-on ("_package"))
  ))