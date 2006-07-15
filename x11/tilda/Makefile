# New ports collection makefile for:	tilda
# Date created:				4 Jan 2005
# Whom:					Vlad V. Teterya <vlad@vlad.uz.ua>
#
# $FreeBSD$
#

PORTNAME=	tilda
PORTVERSION=	0.09.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	vlad@vlad.uz.ua
COMMENT=	Drop down x11 terminal with transparency support

LIB_DEPENDS=	confuse.0:${PORTSDIR}/devel/libconfuse

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	glib20 vte
USE_GCC=	3.4+

PLIST_FILES=	bin/tilda
PORTDOCS=	AUTHORS ChangeLog README TODO

post-patch:
	@${REINPLACE_CMD} -e 's|ps -C tilda -o pid=|pgrep tilda|' \
		${WRKSRC}/src/tilda.c

post-install:
.if !defined (NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

	@${ECHO_MSG} ""
	@${ECHO_MSG} ""
	@${ECHO_MSG} "		ATTENTION:"
	@${ECHO_MSG} "		If you are upgrade from version 0.09.1 or below,"
	@${ECHO_MSG} "		you'll need to delete your old config files and "
	@${ECHO_MSG} "		make them again."
	@${ECHO_MSG} ""
	@${ECHO_MSG} ""

.include <bsd.port.mk>
