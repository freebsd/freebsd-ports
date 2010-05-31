# New ports collection makefile for:	sakura
# Date created:				2008/06/20
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	sakura
PORTVERSION=	2.3.7
PORTREVISION=	2
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	http://www.pleyades.net/david/projects/sakura/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A terminal emulator based on GTK and VTE

USE_GNOME=	vte
USE_GETTEXT=	yes
USE_CMAKE=	yes

MAN1=		sakura.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile
.endif

post-patch:
	@${REINPLACE_CMD} -e '/NOT MATCHES "Debug"/d ; \
		 /"-O2"/d ; \
		's,share/man,man,g' ; \
		 /FILES INSTALL/d' ${WRKSRC}/CMakeLists.txt

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
