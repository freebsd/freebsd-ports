# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	desktop
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none
PKGNAMEPREFIX=	deforaos-

MAINTAINER=	olivier@cochard.me
COMMENT=	Deforaos distribution metaport

RUN_DEPENDS=	${LOCALBASE}/bin/keyboard:${PORTSDIR}/x11/deforaos-keyboard \
		${LOCALBASE}/bin/panel:${PORTSDIR}/x11/deforaos-panel \
		${LOCALBASE}/bin/browser:${PORTSDIR}/x11-fm/deforaos-browser \
		${LOCALBASE}/bin/locker:${PORTSDIR}/x11/deforaos-locker \
		${LOCALBASE}/bin/pdfviewer:${PORTSDIR}/print/deforaos-pdfviewer \
		${LOCALBASE}/bin/mailer:${PORTSDIR}/mail/deforaos-mailer \
		${LOCALBASE}/bin/surfer:${PORTSDIR}/www/deforaos-surfer \
		${LOCALBASE}/bin/todo:${PORTSDIR}/deskutils/deforaos-todo \
		${LOCALBASE}/bin/player:${PORTSDIR}/multimedia/deforaos-player \
		${LOCALBASE}/bin/mixer:${PORTSDIR}/audio/deforaos-mixer \
		${LOCALBASE}/bin/editor:${PORTSDIR}/editors/deforaos-editor \
		${LOCALBASE}/bin/phone:${PORTSDIR}/comms/deforaos-phone

NO_BUILD=	yes
NO_MTREE=	yes

do-install:

pre-everything::
	@${ECHO_MSG} "This is a meta-port, meaning that it just depends on its subparts of the port."
	@${ECHO_MSG} "It won't build and install all the parts until you have typed make install"
	@${ECHO_MSG} "This port does not ensure things are upgraded; use pkgng/portmaster if you want to"
	@${ECHO_MSG} "upgrade Defora."
	@${ECHO_MSG} ""

.include <bsd.port.mk>
