# New ports collection makefile for:    wmmsg
# Date created:         22 January 2004
# Whom:                 Thomas Kempka <t.kempka@web.de>
#
# $FreeBSD$
#

PORTNAME=	wmmsg
PORTVERSION=	1.0
PORTREVISION=	8
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://mirror.israel.net/pub/FreeBSD/distfiles/

MAINTAINER=	t.kempka@web.de
COMMENT=	Dockapp that notifies you on ICQ, AIM and IRC events

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GNOME=	gtk12
USE_BZIP2=	yes
USE_XORG=	xpm
USE_EFL=	imlib2
GNU_CONFIGURE=	yes

MAN1=		wmmsg.1

post-patch:
	@${REINPLACE_CMD} -e 's|exit (|_exit(|g' \
		${WRKSRC}/src/wmgeneral/wmgeneral.c \
		${WRKSRC}/src/wmgeneral/misc.c
	@${REINPLACE_CMD} -e 's|long currtime\;|time_t currtime\;|g' \
		${WRKSRC}/src/wmmsg/wmmsg.c
	@${REINPLACE_CMD} -e 's| man\/wmmsg_notify\.1||g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${ECHO_MSG} "===>   Installing wmmsgrc.dist to ${DOCSDIR}"
	@${INSTALL_DATA} ${WRKSRC}/wmmsgrc ${DOCSDIR}/wmmsgrc.dist
.endif

.include <bsd.port.mk>
