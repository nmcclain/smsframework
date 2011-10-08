<?php

// $Id$

/**
 * @file
 * Rules module support of the smsframework.
 */

/**
 * Implements hook_rules_event_info() on behalf of the smsframework module.
 */
function sms_rules_event_info() {
  return array(
    'sms_incoming' => array(
      'label' => t('A SMS message is received'),
      'help' => t("XXX TODO"),
      'access callback' => TRUE, # XXX TODO!
      'module' => 'sms',
      'group' => t('SMS Framework'),
      'variables' => array(
        'sms' => array(
          'label' => t('SMS Message'),
          'description' => t('The SMS message and metadata.'),
          'type' => 'sms',
        ),
      ),
    ),
  );
}

/**
 * Implements hook_rules_data_info() on behalf of the smsframework module.
 */
function sms_rules_data_info() {
  return array(
    'sms' => array(
      'label' => t('SMS Message'),
      'wrap' => TRUE,
      'property info' => _sms_rules_sms_info(),
    ),
  );
}

/**
 * Defines property info for sms messages.
 */
function _sms_rules_sms_info() {
  return array(
    'number' => array(
      'type' => 'text',
      'label' => t('The number which sent the SMS message'),
    ),
    'message' => array(
      'type' => 'text',
      'label' => ('The SMS message'),
      'sanitized' => FALSE,
    ),
  );
}

/**
 * Implements hook_rules_action_info() on behalf of the system module.
 */
function sms_rules_action_info() {
  return array(
    'sms' => array(
      'label' => t('Send sms'),
      'group' => t('SMS'),
      'parameter' => array(
        'to' => array(
          'type' => 'text',
          'label' => t('To'),
          'description' => t('The destination SMS number'),
        ),
        'message' => array(
          'type' => 'text',
          'label' => t('Message'),
          'description' => t("The sms message body."),
        ),
      ),
      'base' => 'rules_action_sms',
      'access callback' => TRUE, # XXX
    ),
  );
}

/**
 * Action Implementation: Send sms.
 */
function rules_action_sms($to, $message) {
  if (!sms_send($to, $message)) {
    watchdog('sms', 'Failed to send sms to %recipient', array('%recipient' => $to));
  }
  else {
    watchdog('sms', 'Successfully sent sms to %recipient', array('%recipient' => $to));
  }
}

