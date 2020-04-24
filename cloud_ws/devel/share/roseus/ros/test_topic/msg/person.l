;; Auto-generated. Do not edit!


(when (boundp 'test_topic::person)
  (if (not (find-package "TEST_TOPIC"))
    (make-package "TEST_TOPIC"))
  (shadow 'person (find-package "TEST_TOPIC")))
(unless (find-package "TEST_TOPIC::PERSON")
  (make-package "TEST_TOPIC::PERSON"))

(in-package "ROS")
;;//! \htmlinclude person.msg.html


(intern "*UNKONW*" (find-package "TEST_TOPIC::PERSON"))
(shadow '*UNKONW* (find-package "TEST_TOPIC::PERSON"))
(defconstant test_topic::person::*UNKONW* 0)
(intern "*MALE*" (find-package "TEST_TOPIC::PERSON"))
(shadow '*MALE* (find-package "TEST_TOPIC::PERSON"))
(defconstant test_topic::person::*MALE* 1)
(intern "*FEMALE*" (find-package "TEST_TOPIC::PERSON"))
(shadow '*FEMALE* (find-package "TEST_TOPIC::PERSON"))
(defconstant test_topic::person::*FEMALE* 2)
(defclass test_topic::person
  :super ros::object
  :slots (_name _sex _age ))

(defmethod test_topic::person
  (:init
   (&key
    ((:name __name) "")
    ((:sex __sex) 0)
    ((:age __age) 0)
    )
   (send-super :init)
   (setq _name (string __name))
   (setq _sex (round __sex))
   (setq _age (round __age))
   self)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:sex
   (&optional __sex)
   (if __sex (setq _sex __sex)) _sex)
  (:age
   (&optional __age)
   (if __age (setq _age __age)) _age)
  (:serialization-length
   ()
   (+
    ;; string _name
    4 (length _name)
    ;; uint8 _sex
    1
    ;; uint8 _age
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;; uint8 _sex
       (write-byte _sex s)
     ;; uint8 _age
       (write-byte _age s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint8 _sex
     (setq _sex (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _age
     (setq _age (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get test_topic::person :md5sum-) "f523df5f672923005c184b91d515558c")
(setf (get test_topic::person :datatype-) "test_topic/person")
(setf (get test_topic::person :definition-)
      "string name
uint8 sex
uint8 age

uint8 unkonw=0
uint8 male=1
uint8 female=2


")



(provide :test_topic/person "f523df5f672923005c184b91d515558c")


