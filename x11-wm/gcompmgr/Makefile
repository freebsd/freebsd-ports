# New ports collection makefile for:	gcompmgr
# Date created:				6 Feb 2006
# Whom:					UMENO Takashi
#
# $FreeBSD$
#

PORTNAME=	gcompmgr
PORTVERSION=	0.21
PORTREVISION=	4
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gcompmgr

MAINTAINER=	umeno@rr.iij4u.or.jp
COMMENT=	A GNOME interface to xcompmgr

RUN_DEPENDS=	xcompmgr:${PORTSDIR}/x11-wm/xcompmgr
LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake:19:env

DESKTOP_ENTRIES="gcompmgr" \
		"Configure window effects" \
		"" \
		"gcompmgr" \
		"Application;Settings;" \
		true


post-patch:
.for file in depcomp install-sh missing
	@${LN} -sf ${AUTOMAKE_DIR}/${file} ${WRKSRC}
.endfor
	@${REINPLACE_CMD} -e 's|connect(SigC::slot|connect(sigc::mem_fun|g ; \
		s|#include <sigc++\/compatibility\.h>||g' \
			${WRKSRC}/src/*.cc

.include <bsd.port.mk>
