# Ports collection Makefile for:	fluxconf
# Date created:				29/04/2002
# Whom:					hendrik@scholz.net
#
# $FreeBSD$
#

PORTNAME=	fluxconf
PORTVERSION=	0.6
CATEGORIES=	x11-wm
MASTER_SITES=	http://devaux.fabien.free.fr/flux/

MAINTAINER=	hendrik@scholz.net

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_BZIP2=	yes

.ifndef(WITHOUT_LOGO)
pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} "You can disable the spash logo when starting the"
	@${ECHO_CMD} "program by defining WITHOUT_LOGO"
	@${ECHO_CMD} ""
.endif

post-patch:
	@${RM} ${WRKSRC}/fluxconf

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/fluxconf ${PREFIX}/bin
	@${LN} -s ${PREFIX}/bin/fluxconf ${PREFIX}/bin/fluxkeys

.include <bsd.port.mk>
