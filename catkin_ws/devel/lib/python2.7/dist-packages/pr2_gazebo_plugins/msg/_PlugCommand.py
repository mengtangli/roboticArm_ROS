"""autogenerated by genpy from pr2_gazebo_plugins/PlugCommand.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class PlugCommand(genpy.Message):
  _md5sum = "852b7035ee3e7fa6390824cf7b7e6dd1"
  _type = "pr2_gazebo_plugins/PlugCommand"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """bool ac_present
float64 charge_rate
float64 discharge_rate
float64 charge

"""
  __slots__ = ['ac_present','charge_rate','discharge_rate','charge']
  _slot_types = ['bool','float64','float64','float64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       ac_present,charge_rate,discharge_rate,charge

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(PlugCommand, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.ac_present is None:
        self.ac_present = False
      if self.charge_rate is None:
        self.charge_rate = 0.
      if self.discharge_rate is None:
        self.discharge_rate = 0.
      if self.charge is None:
        self.charge = 0.
    else:
      self.ac_present = False
      self.charge_rate = 0.
      self.discharge_rate = 0.
      self.charge = 0.

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_struct_B3d.pack(_x.ac_present, _x.charge_rate, _x.discharge_rate, _x.charge))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 25
      (_x.ac_present, _x.charge_rate, _x.discharge_rate, _x.charge,) = _struct_B3d.unpack(str[start:end])
      self.ac_present = bool(self.ac_present)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_struct_B3d.pack(_x.ac_present, _x.charge_rate, _x.discharge_rate, _x.charge))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 25
      (_x.ac_present, _x.charge_rate, _x.discharge_rate, _x.charge,) = _struct_B3d.unpack(str[start:end])
      self.ac_present = bool(self.ac_present)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_B3d = struct.Struct("<B3d")
