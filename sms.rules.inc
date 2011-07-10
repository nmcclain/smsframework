<?php

/**
 * @file
 * Rules module support of the smsframework.
 */

/**
 * Implements hook_rules_event_info().
 */
function sms_rules_event_info() {
  return array(
    'sms_incoming' => array(
      'label' => t('When a SMS message is received'),
      'access callback' => TRUE, # XXX
      'module' => 'sms',
      'group' => t('SMS Framework'),
      'variables' => array(
        'number' => array(
          'label' => t('SMS Number'),
          'description' => t('The SMS number that sent the message.'),
          'type' => 'text',
        ),
        'message' => array(
          'label' => t('SMS Message'),
          'description' => t('The SMS message that was received.'),
          'type' => 'text',
        ),
      ),
    ),
  );
}

