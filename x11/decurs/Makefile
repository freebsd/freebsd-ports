# New ports collection makefile for:   decurs
# Date created:		19 January 2002
# Whom:			Miguel Mendez <flynn@energyhq.homeip.net>
#
# $FreeBSD$
#

PORTNAME=	decurs
PORTVERSION=	0.50.0
CATEGORIES=	x11
MASTER_SITES=	http://www.hut.fi/~pvsavola/files/

MAINTAINER=	adam@vectors.cx

LIB_DEPENDS=	gtkmm.2:${PORTSDIR}/x11-toolkits/gtk--

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

# The Makefile doesn't provide a install target
post-install:
		@$(INSTALL) $(WRKSRC)/src/decurs $(X11BASE)/bin
		@$(ECHO) "	################################################"
		@$(ECHO) "	To use this program, please copy "
		@$(ECHO) "	$(WRKSRC)/src/fonts/*.bdf"
		@$(ECHO) "	somewhere else and invoke "$(PORTNAME)
		@$(ECHO) "	from that directory."
		@$(ECHO) "	################################################"

.include <bsd.port.mk>
