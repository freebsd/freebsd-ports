# New ports collection makefile for:	fvwm
# Version required:	1.23b
# Date created:		25 August 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.1.1.1 1994/08/25 21:04:07 jkh Exp $
#

DISTNAME=	fvwm-1.23b
WRKSRC=		${.CURDIR}/work
HOME_LOCATION=	ftp://spcot.sanders.com/pub/fvwm
USE_IMAKE=	yes

# Gack!  This is annoyingly necessary, since fvwm comes in 3 parts
# and I've no easy way of coping in the default rules.
EXTRACT_COOKIE=	${.CURDIR}/.extract_done
extract: ${EXTRACT_COOKIE}
${EXTRACT_COOKIE}:
	@echo "===>  Extracting for ${DISTNAME}"
	@rm -rf ${WRKDIR}
	@mkdir -p ${WRKDIR}
	@if [ ! -f ${DISTDIR}/fvwm-1.23b-core.tar.gz ]; then \
	   echo ">> Sorry, can't find: ${DISTDIR}/fvwm-1.23b-core.tar.gz"; \
	   echo ">> Please obtain this file from:"; \
	   echo ">>	${HOME_LOCATION}"; \
	   echo ">>before proceeding."; \
	   exit 1; \
	fi
	@${EXTRACT_CMD} ${EXTRACT_ARGS} ${DISTDIR}/fvwm-1.23b-core.tar.gz
	@if [ -f ${DISTDIR}/fvwm-1.23b-modules.tar.gz ]; then \
	   ${EXTRACT_CMD} ${EXTRACT_ARGS} ${DISTDIR}/fvwm-1.23b-modules.tar.gz;\
	fi
	@if [ -f ${DISTDIR}/fvwm-1.23-icons.tar.gz ]; then \
	   ${EXTRACT_CMD} ${EXTRACT_ARGS} ${DISTDIR}/fvwm-1.23-icons.tar.gz; \
	fi
	@touch -f ${EXTRACT_COOKIE}

.include <bsd.port.mk>
