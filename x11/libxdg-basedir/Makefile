# Created by: Nikos Ntarmos <ntarmos@cs.uoi.gr>

PORTNAME=	libxdg-basedir
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://nevill.ch/libxdg-basedir/downloads/

MAINTAINER=	ntarmos@ceid.upatras.gr
COMMENT=	Implementation of the XDG Base Directory specification

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix
USE_LDCONFIG=	yes

pre-configure:
	@${REINPLACE_CMD} -e 's|"etc"|"${PREFIX}/etc"|' \
		-e '/DefaultConfigDirectories\[\]/,/DefaultRelativeCacheHome\[\]/ s|"/\([^"]\)|"\1|' \
		-e '/DefaultConfigDirectories\[\]/,/DefaultRelativeCacheHome\[\]/ s|/|" DIR_SEPARATOR_STR "|g' \
		${WRKSRC}/src/basedir.c

.include <bsd.port.mk>
